#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.setWindowTitle("Учет инвентаря на складах предприятия");
   // w.showMaximized();
    w.show();

    return a.exec();
}
