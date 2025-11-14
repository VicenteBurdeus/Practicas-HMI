#include "mainwindow.h"
#include"tabla/dialogpersona.h"
#include"tabla/tablewindow.h"
#include <QApplication>
#include<QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DialogPersona dp;
    TableWindow tp;
    QFile file(":/estilos/estilo.qss"); // Asegúrate de que el archivo esté en el recurso
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        tp.setStyleSheet(styleSheet);
        file.close();
    }
    //w.show();
   // dp.show();
    tp.setWindowTitle("Vista tabla personas");
    tp.show();
    return a.exec();
}
