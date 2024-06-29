
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPalette pal = w.palette();
    pal.setColor(QPalette::Window, QColor("#ffffff"));
    w.setWindowTitle("QudraSolver");
    w.showMaximized();
    return a.exec();
}
