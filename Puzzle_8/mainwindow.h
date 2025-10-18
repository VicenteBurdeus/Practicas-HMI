#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void resetGame(); // Slot que se conecta al botón de reset

private:

    Ui::MainWindow *ui;

    QLabel *labelMoves; // Referencia al label de movimientos
    int moves; // Variable que guarda el número de movimientos
    QPushButton *buttons[8]; // Vector para referenciar a los botones en un for
    QPushButton *emptyButton; // Botón sin texto
    int emptyButtonRow, emptyButtonCol; // Posición del botón vacío
    QGridLayout *gridLayout; // Referencia al gridLayout
    QPair<int, std::array<int,4>> movimientos;

    void updateMoves();
    void randomizeButtons();
    bool isSolvable();


    void updateBoard();
    void hold_square();


    void canMove();
    void pressedButton(QPushButton*);
    int matriz_juego[3][3];

protected:
    void resizeEvent(QResizeEvent *event) override;

};

#endif // MAINWINDOW_H
