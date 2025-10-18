#include "mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include <math.h>
#include <QTimer>
#include <algorithm> // std::random_shuffle
#include <cstdlib> // std::rand, std::srand
#include <ctime> // std::time
#include <QDebug>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , moves(0)
{
    ui->setupUi(this);
    ui->gridLayout->installEventFilter(this);
    setWindowTitle("Puzzle 8 - HMI Burdeus");


    QFile file(":/estilos/estilos.qss"); // Ruta al archivo en el recurso
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QString::fromUtf8(file.readAll());
        this->setStyleSheet(styleSheet);
        file.close();
    }

    // Inicializar el randomizador
    std::srand(std::time(nullptr));


    // aqui desarrollar el código necesario
    //Asignacion de botones
    buttons[0] = ui->pushButton1;
    buttons[1] = ui->pushButton2;
    buttons[2] = ui->pushButton3;
    buttons[3] = ui->pushButton4;
    buttons[4] = ui->pushButton5;
    buttons[5] = ui->pushButton6;
    buttons[6] = ui->pushButton7;
    buttons[7] = ui->pushButton8;
    emptyButton = ui->emptyButton;

    for (int i = 0; i < 8; ++i) {
        connect(buttons[i], &QPushButton::clicked, [=](){ pressedButton(buttons[i]); });
    }


    gridLayout = ui->gridLayout;
    labelMoves = ui->labelMoves;

    QFont font = buttons[0]->font();
    font.setPointSize(48);
    font.bold();
    for (int i = 0; i<8;i++){
        buttons[i]->setText(QString::number(i+1));
        buttons[i]->setFont(font);
    }
    labelMoves->setFont(font);
    emptyButton->setText("");
    emptyButton->hide();

    ui->button_NewGame->setText("↻ Nueva Partida");
    ui->button_NewGame->setStyleSheet(
        "color: black;"       // color del texto
        "background-color: #8BB06F;" //lima
        "font-weight: bold;"
        "font-size: 18pt;"
        );


    //interrupciones
    connect(ui->button_NewGame, &QPushButton::clicked, this, &MainWindow::resetGame);
    QTimer::singleShot(0, this, &MainWindow::hold_square);
    QTimer::singleShot(0, this, &MainWindow::resetGame);


}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    hold_square();
}
void MainWindow::hold_square()
{
    QWidget *central = ui->centralwidget; // tu central widget real
    QMargins margins = gridLayout->contentsMargins();

    int availableWidth = central->width() - margins.left() - margins.right() - gridLayout->spacing() * 2;
    int availableHeight = central->height() - margins.top() - margins.bottom() - gridLayout->spacing() * 2;

    int size = qMin(availableWidth, availableHeight) * 0.8 / 3;

    if (size < 16) size = 16;


    for (int i = 0; i < 8; i++) {
        buttons[i]->setFixedSize(size, size);
    }
    emptyButton->setFixedSize(size, size);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::canMove(){

    qDebug() << "Estado actual de la matriz:";
    for (int i = 0; i < 3; ++i) {
        QString row;
        for (int j = 0; j < 3; ++j) {
            row += QString::number(matriz_juego[i][j]) + " ";
        }
        qDebug() << row;
    }

    //la primera parte dice cuantos movimientos posibles a encontrado y la segunda dice cuales son los botones pulsables
    QPair<int, std::array<int,4>> par = qMakePair(0, std::array<int,4>{0,0,0,0});

    int movesFound = 0;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // Restaurar el color original de todos los botones
    for (int i = 0; i < 8; ++i)
    {
        buttons[i]->setStyleSheet(""); // quita el estilo previo
    }

    for (int k = 0; k < 4; ++k)
    {
        int newRow = emptyButtonRow + dr[k];
        int newCol = emptyButtonCol + dc[k];

        if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3)
        {
            int value = matriz_juego[newRow][newCol];
            if (value != 0)
            {
                int buttonIndex = value - 1;
                par.second[movesFound] = buttonIndex;
                movesFound++;

                // Poner fondo azul cian al botón que se puede mover
                buttons[buttonIndex]->setStyleSheet(
                    "background-color: cyan; color: black; font-weight: bold;"
                    );
            }
        }
    }

    par.first = movesFound;
    movimientos =  par;
    update();
}

void MainWindow::pressedButton(QPushButton* button)
{
    int buttonNumber = button->text().toInt();
    int buttonIndex = buttonNumber - 1;

    // Primero comprobamos si el botón puede moverse
    bool canMoveFlag = false;
    for (int i = 0; i < movimientos.first; ++i) {
        if (movimientos.second[i] == buttonIndex) {
            canMoveFlag = true;
            break;
        }
    }
    if (!canMoveFlag)
        return;

    // Encontrar la posición actual del botón en la matriz
    int rowBtn = 0, colBtn = 0;
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (matriz_juego[r][c] == buttonNumber) {
                rowBtn = r;
                colBtn = c;
            }
        }
    }

    // Calcular dirección de movimiento
    int dRow = emptyButtonRow - rowBtn;
    int dCol = emptyButtonCol - colBtn;

    // Solo movimientos adyacentes permitidos
    if ((abs(dRow) + abs(dCol)) != 1) return;

    // Obtener la geometría actual y la geometría destino del hueco
    QRect startGeom = button->geometry();
    QRect endGeom = gridLayout->cellRect(emptyButtonRow, emptyButtonCol);

    // Crear animación de deslizamiento
    QPropertyAnimation* anim = new QPropertyAnimation(button, "geometry");
    anim->setDuration(100);
    anim->setStartValue(startGeom);
    anim->setEndValue(endGeom);
    anim->start(QAbstractAnimation::DeleteWhenStopped);

    // Actualizar la matriz inmediatamente
    matriz_juego[emptyButtonRow][emptyButtonCol] = buttonNumber;
    matriz_juego[rowBtn][colBtn] = 0;

    //suma un movimiento al contador
    moves++;
    updateMoves();

    // Al terminar la animación, asegurar que el botón quede en el layout
    connect(anim, &QPropertyAnimation::finished, [=]() {
        gridLayout->addWidget(button, emptyButtonRow, emptyButtonCol);
        emptyButtonRow = rowBtn;
        emptyButtonCol = colBtn;
        canMove(); // actualizar resaltado de botones movibles
    });
}



void MainWindow::resetGame()
{
    randomizeButtons();
    while (!isSolvable()) {
        randomizeButtons();
    }
    moves = 0;
    updateMoves();
    canMove();
}

void MainWindow::updateMoves()
{
    labelMoves->setText(QString::number(moves));
}

void MainWindow::randomizeButtons()
{
    // Obtener una lista de las posiciones posibles en el grid
    QList<QPair<int, int>> positions;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            positions.append(qMakePair(row, col));
        }
    }

    // Mezclar las posiciones aleatoriamente
    std::random_shuffle(positions.begin(), positions.end());

    // Asignar los botones a las posiciones aleatorias
    for (int i = 0; i < 8; ++i) {
        gridLayout->addWidget(buttons[i], positions[i].first, positions[i].second);
        matriz_juego[positions[i].first][positions[i].second] = i+1;
    }

    // Asignar la posición del hueco vacío
    emptyButtonRow = positions[8].first;
    emptyButtonCol = positions[8].second;
    matriz_juego[emptyButtonRow][emptyButtonCol] = 0;
    gridLayout->addWidget(emptyButton, emptyButtonRow, emptyButtonCol);
}

bool MainWindow::isSolvable()
{
    // Crear una lista con los números de las piezas, omitiendo el hueco vacío
    QList<int> list;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; j++) {
            QLayoutItem *item = gridLayout->itemAtPosition(i, j); // Obtener el QLayoutItem en la posición 'i'

            if (item->widget()) { // Comprobar si el QLayoutItem tiene un widget asociado
                QWidget *widget = item->widget(); // Obtener el widget del item

                // Saber el tipo de widget
                if (QPushButton *button = qobject_cast<QPushButton *>(widget)) {
                    if (button != emptyButton) {
                        list.append(button->text().toInt());
                    }
                }
            }
        }
    }

    // Calcular el número de inversiones
    int inversions = 0;
    for (int i = 0; i < list.size() - 1; ++i) {
        for (int j = i + 1; j < list.size(); ++j) {
            if (list[i] > list[j]) {
                inversions++;
            }
        }
    }

    // Un puzzle es resoluble si el número de inversiones es par
    return (inversions % 2 == 0);
}
