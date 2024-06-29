#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMainWindow>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QMouseEvent>
#include <QGuiApplication>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void drawVectorToPoint(QPoint point);
    void paintEvent(QPaintEvent* ) override;
private:
    Ui::MainWindow *ui;
    QPainter painter;
};
#endif // MAINWINDOW_H
