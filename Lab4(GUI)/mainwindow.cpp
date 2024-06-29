#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "comnum.h"
#include "math.h"
#include "QPainter"
#include "PolskaZapis.h"
#include "CalculatePolska.h"
#include <fstream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui->pushButton->setGeometry(QGuiApplication::primaryScreen()->geometry().height(),
    //                             QGuiApplication::primaryScreen()->geometry().height()-200*QGuiApplication::primaryScreen()->geometry().height()/800,
    //                             QGuiApplication::primaryScreen()->geometry().width()-QGuiApplication::primaryScreen()->geometry().height(),
    //                             105*QGuiApplication::primaryScreen()->geometry().height()/800);
    ui->label_1->setGeometry(QGuiApplication::primaryScreen()->geometry().height(),
                             0,
                             (QGuiApplication::primaryScreen()->geometry().width()-QGuiApplication::primaryScreen()->geometry().height())/2,
                             30);
    ui->label_2->setGeometry(QGuiApplication::primaryScreen()->geometry().height()+(QGuiApplication::primaryScreen()->geometry().width()-QGuiApplication::primaryScreen()->geometry().height())/2,
                             0,
                             (QGuiApplication::primaryScreen()->geometry().width()-QGuiApplication::primaryScreen()->geometry().height())/2,
                             30);
    ui->label_1->setStyleSheet("font-size: 20px");
    ui->label_2->setStyleSheet("font-size: 20px");
    //vert
    ui->label_Im->setGeometry(QGuiApplication::primaryScreen()->geometry().height()/2,
                              0,
                              38,
                              20);
    ui->label_Im->setStyleSheet("font-size: 20px");
    //hor
    ui->label_Re->setGeometry(QGuiApplication::primaryScreen()->geometry().height()*0.885,
                              QGuiApplication::primaryScreen()->geometry().height()/2-QGuiApplication::primaryScreen()->geometry().height()*0.1,
                              38,
                              20);
    ui->label_Re->setStyleSheet("font-size: 20px");
    ui->label_degree_1->setGeometry(QGuiApplication::primaryScreen()->geometry().height(),
                                    50,
                                    (QGuiApplication::primaryScreen()->geometry().width()-QGuiApplication::primaryScreen()->geometry().height())/2,
                                    20);
    ui->label_degree_2->setGeometry(QGuiApplication::primaryScreen()->geometry().height()+(QGuiApplication::primaryScreen()->geometry().width()-QGuiApplication::primaryScreen()->geometry().height())/2,
                                    50,
                                    (QGuiApplication::primaryScreen()->geometry().width()-QGuiApplication::primaryScreen()->geometry().height())/2,
                                    20);
    ui->label_kord_1->setGeometry(QGuiApplication::primaryScreen()->geometry().height(),
                                  95,
                                  (QGuiApplication::primaryScreen()->geometry().width()-QGuiApplication::primaryScreen()->geometry().height())/2,
                                  40);
    ui->label_kord_2->setGeometry(QGuiApplication::primaryScreen()->geometry().height()+(QGuiApplication::primaryScreen()->geometry().width()-QGuiApplication::primaryScreen()->geometry().height())/2,
                                  95,
                                  (QGuiApplication::primaryScreen()->geometry().width()-QGuiApplication::primaryScreen()->geometry().height())/2,
                                  40);
    ui->label_degree_1->setStyleSheet("font-size: 20px");
    ui->label_degree_2->setStyleSheet("font-size: 20px");
    ui->label_kord_1->setStyleSheet("font-size: 20px");
    ui->label_kord_2->setStyleSheet("font-size: 20px");
    ui->label_Im->setStyleSheet("font-size: 20px");
    ui->label_Re->setStyleSheet("font-size: 20px");
    update();
}

void MainWindow::drawVectorToPoint(QPoint point)
{
    painter.drawLine(height()/2.0, height()/2.0,point.x(),point.y());
    if (point.x() != height()/2 or point.y() != height()/2)
    {
        double x_dif = copysign(1, point.x()-height()/2);
        double y_dif = copysign(1, point.y()-height()/2);
        if (point.x() == height()/2)
        {
            painter.drawLine(point.x(),
                             point.y(),
                             point.x()*1.0125,
                             point.y()+y_dif*height()*0.0125);
            painter.drawLine(point.x(),
                             point.y(),
                             point.x()*0.9875,
                             point.y()+y_dif*height()*0.0125);
        }
        else if (point.y() == height()/2)
        {
            painter.drawLine(point.x(),
                             point.y(),
                             point.x()-x_dif*height()*0.0125,
                             point.y()*1.0125);
            painter.drawLine(point.x(),
                             point.y(),
                             point.x()-x_dif*height()*0.0125,
                             point.y()*0.9875);
        }
        else
        {
            painter.drawLine(point.x(),
                             point.y(),
                             point.x(),
                             point.y()-y_dif*height()*0.0125);
            painter.drawLine(point.x(),
                             point.y(),
                             point.x()-x_dif*height()*0.0125,
                             point.y());
        }
    }
}

void MainWindow::paintEvent(QPaintEvent* )
{
    ComNum r1;
    ComNum r2;
    string astr;
    string bstr;
    string cstr;
    bool SingleMode;
    painter.begin(this);
    ifstream get_string("input.txt");
    get_string >> astr;
    get_string >> bstr;
    get_string >> cstr;
    if (!(astr.empty() or bstr.empty() or cstr.empty() or astr=="error" or bstr=="error" or cstr=="error"))
    {
        ui->label_Im->setText("Im z");
        ui->label_Re->setText("Re z");
        {
            double a = CalculatePolskaZapis(getPolskaZapis(astr));
            double b = CalculatePolskaZapis(getPolskaZapis(bstr));
            double c = CalculatePolskaZapis(getPolskaZapis(cstr));
            double d = b*b - 4*a*c;
            if (a == 0 )
            {
                ui->label_1->setText("");
                ui->label_2->setText("");
                ui->label_degree_1->setText("");
                ui->label_degree_2->setText("");
                ui->label_kord_1->setText("");
                ui->label_kord_2->setText("");
                if(b==0)
                {
                    ui->label_1->setText("Корень : любое значение");
                }
                else
                {
                    r1.SetRe(-c/b);
                    ui->label_1->setText("Корень : " + QString::number(r1.GetRe()));
                    ui->label_kord_1->setText("Вектор : (" + QString::number(r1.GetRe()) + "," + QString::number(r1.GetIm()) + ")");
                    ui->label_degree_1->setText("Угол : " + r1.ShowDegreeLikeQStr());
                }
                SingleMode = 1;
            }
            else if (d <= 0)
            {
                r1.SetRe(-b/(2*a));
                r1.SetIm(sqrt(-d)/(2*a));
                r2.SetRe(-b/(2*a));
                r2.SetIm(-sqrt(-d)/(2*a));
                if (d != 0)
                {
                    ui->label_1->setText("Корень 1: " + r1.ShowLikeQStr());
                    ui->label_2->setText("Корень 2: " + r2.ShowLikeQStr());
                    ui->label_degree_1->setText("Угол 1: " + r1.ShowDegreeLikeQStr());
                    ui->label_degree_2->setText("Угол 2: " + r2.ShowDegreeLikeQStr());
                    ui->label_kord_1->setText("Вектор 1: (" + QString::number(r1.GetRe()) + "," + QString::number(r1.GetIm()) + ")");
                    ui->label_kord_2->setText("Вектор 2: (" + QString::number(r2.GetRe()) + "," + QString::number(r2.GetIm()) + ")");
                    SingleMode = 0;
                }
                else
                {
                    ui->label_1->setText("Корень : " + r1.ShowLikeQStr());
                    ui->label_2->setText("");
                    ui->label_degree_1->setText("Угол : " + r1.ShowDegreeLikeQStr());
                    ui->label_degree_2->setText("");
                    ui->label_kord_1->setText("Вектор : (" + QString::number(r1.GetRe()) + "," + QString::number(r1.GetIm()) + ")");
                    ui->label_kord_2->setText("");
                    SingleMode = 1;
                }
            }
            else
            {
                r1.SetRe((-b + sqrt(d))/(2*a));
                r1.SetIm(0);
                r2.SetRe((-b - sqrt(d))/(2*a));
                r2.SetIm(0);
                ui->label_1->setText("Корень 1: " + r1.ShowLikeQStr());
                ui->label_2->setText("Корень 2: " + r2.ShowLikeQStr());
                ui->label_degree_1->setText("Угол 1: " + r1.ShowDegreeLikeQStr());
                ui->label_degree_2->setText("Угол 2: " + r2.ShowDegreeLikeQStr());
                ui->label_kord_1->setText("Вектор 1: (" + QString::number(r1.GetRe()) + "," + QString::number(r1.GetIm()) + ")");
                ui->label_kord_2->setText("Вектор 2: (" + QString::number(r2.GetRe()) + "," + QString::number(r2.GetIm()) + ")");
                SingleMode = 0;
            }
            double max = r1.GetMax();
            double n = 1;
            if(r2.GetMax()>max)
            {
                max = r2.GetMax();
            }
            while(!(max*n>=1 && max*n<=10) && (max != 0))
            {
                if(max<1)
                    n*=10;
                else
                    n*=0.1;
            }
            QPoint point1 (height()/2.0 + r1.GetRe()*n*0.95*height()/20.0, height()/2.0 - r1.GetIm()*n*0.95*height()/20.0);
            double radian1 = sqrt((point1.x()-height()/2)*(point1.x()-height()/2) + (point1.y()-height()/2)*(point1.y()-height()/2));
            painter.drawEllipse(height()/2-radian1,height()/2-radian1,2*radian1,2*radian1);
            double x_dif_1 = point1.x() - height()/2;
            double y_dif_1 = point1.y() - height()/2;
            painter.drawText(QPoint(point1.x()+x_dif_1*0.125, point1.y()+y_dif_1*0.125),QString(r1.ShowDegreeLikeQStr()) + QString("\n(" + QString::number(r1.GetRe())  + "," + QString::number(r1.GetIm()) + ")"));
            drawVectorToPoint(point1);
            if (!SingleMode)
            {
                QPoint point2 (height()/2.0 + r2.GetRe()*n*0.95*height()/20.0, height()/2.0 - r2.GetIm()*n*0.95*height()/20.0);
                double radian2 = sqrt((point2.x()-height()/2)*(point2.x()-height()/2) + (point2.y()-height()/2)*(point2.y()-height()/2));
                painter.drawEllipse(height()/2-radian2,height()/2-radian2,2*radian2,2*radian2);
                double x_dif_2 = point2.x() - height()/2;
                double y_dif_2 = point2.y() - height()/2;
                painter.drawText(QPoint(point2.x()+x_dif_2*0.125, point2.y()+y_dif_2*0.125),QString(r2.ShowDegreeLikeQStr()) + QString("\n(" + QString::number(r2.GetRe())  + "," + QString::number(r2.GetIm()) + ")"));
                drawVectorToPoint(point2);
            }
            //horizontal
            painter.drawLine(0, height()/2.0, height(),height()/2.0);

            painter.drawLine(height(), height()/2.0, 0.975*height(),height()/2.0+0.025*height());
            painter.drawLine(height(), height()/2.0, 0.975*height(),height()/2.0-0.025*height());


            //vertical
            painter.drawLine(height()/2, 0, height()/2,height());

            painter.drawLine(height()/2.0-0.025*height(),0.025*height(),height()/2.0,0);
            painter.drawLine(height()/2.0+0.025*height(),0.025*height(),height()/2.0,0);

            int i = -10;
            //vertical
            for (double j=0.025*height(); j <= 0.975*height(); j+=0.0475*height())
            {
                painter.drawLine(j,height()/2-5, j,height()/2+5);
                if (i != 0)
                    painter.drawText(j-3,height()/2+14, QString::number(i/n));
                else
                    painter.drawText(j+3,height()/2+14, QString::number(0));
                i++;
            }
            //horizontal
            i = +10;
            for (double j=0.025*height(); j <= 0.975*height(); j+=0.0475*height())
            {
                painter.drawLine(height()/2-5, j, height()/2+5, j);
                if (i!=0)
                    painter.drawText(height()/2+7, j+3, QString::number(i/n));
                i--;
            }
        }
    }
    else
    {
        ui->label_1->setText("Ошибка ввода");
        ui->label_2->setText("");
        ui->label_degree_1->setText("Перепишите input файл");
        ui->label_degree_2->setText("");
        ui->label_kord_1->setText("");
        ui->label_kord_2->setText("");
    }
    painter.end();
}

MainWindow::~MainWindow()
{
    delete ui;
}
