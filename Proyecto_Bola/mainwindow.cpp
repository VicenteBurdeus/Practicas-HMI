#include "utils.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,gridSize(20, 20)
    ,celdaBola(2, 2)
    ,diameterRatio(0.7)
    ,isDraqueen(0)
{
    ui->setupUi(this);
    connect(ui->sliderTamanyo,&QSlider::valueChanged, this, &Ui::MainWindow::sliderTamanyo);
}

MainWindow::~MainWindow()
{
    delete ui;
}
#if 0
void MainWindow::calcularAreaDibujo(){
    QRect h;
    h.
    MainWindow::gridSize. = (int)ui->sliderTamanyo->value();}
#endif

void MainWindow::setNewSlots(){
    gridSize.setHeight(ui->sliderTamanyo->value());
    gridSize.setWidth(ui->sliderTamanyo->value());
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(QPen(Qt::black, 3));
    Utils::drawGrid(ui->centralwidget->geometry(), gridSize, painter);

    painter.setPen(QPen(Qt::red, 6));
    painter.setBrush(Qt::red);
    Utils::drawCircleCell(ui->centralwidget->geometry(),gridSize,painter,celdaBola,diameterRatio);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch(event->key()){
    case Qt::Key_Up:
        Utils::updatePosition(gridSize,celdaBola,-1,0);
        break;
    case Qt::Key_Down:
        Utils::updatePosition(gridSize,celdaBola,1,0);
        break;
    case Qt::Key_Right:
        Utils::updatePosition(gridSize,celdaBola,0,1);
        break;
    case Qt::Key_Left:
        Utils::updatePosition(gridSize,celdaBola,0,-1);
        break;
    };
    update();
    return;
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() != Qt::LeftButton){return;}
    int row,col;

    if(Utils::getCellFromPosition(event->pos(), ui->centralwidget->geometry(),this->gridSize,row,col)){

    }else{
        celdaBola.setY(row);
        celdaBola.setX(col);
        isDraqueen = true;
    }
    update();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() != Qt::LeftButton){return;}


    isDraqueen = false;
    update();
}



