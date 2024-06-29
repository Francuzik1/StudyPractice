#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <qDebug>
#include <iostream>
#include <string>
#include <QString>
#include <QDataStream>
#include <iostream>
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    string X = "hello";
    string Y = "hi";
    string Z = "Buy";
    ofstream out("data1.bin",ios::binary|ios::out);
    out.write((char*)&X,sizeof X);
    out.write((char*)&Y,sizeof Y);
    out.write((char*)&Z,sizeof Z);
    out.flush();
    out.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    fileName = QFileDialog::getOpenFileName(this,
        "Выбор файла", "C:/", "*.txt ;; *.bin");

    if (fileName[fileName.length()-1] == 't')
    {
        QFile myFile(fileName);
        if (!myFile.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QByteArray a;
        a=myFile.readAll();
        ui->textEdit->setText(QString(a));
        myFile.close();
    }
    else
    {
        fstream in("data1.bin",ios::binary|ios::in);
        QString tmp;
        QString str;
        while (!in.eof())
        {
            in.read((char*)&tmp,sizeof tmp);
            str += tmp;
        }
        in.close();
        ui->textEdit->setText(QString(str));
    }
}


void MainWindow::on_action_2_triggered()
{
    QFile myFile(fileName);

    if (!myFile.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    QByteArray strByteArray = ui->textEdit->toPlainText().toUtf8();
    myFile.write(strByteArray);
    myFile.close();
}


void MainWindow::on_action_3_triggered()
{
    fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "/newDoc.txt", tr("myDoc *.txt ;; myDoc *.bin"));

    if(!fileName.isEmpty())
    {
        QFile myFile(fileName);
        if (!myFile.open(QIODevice::WriteOnly | QIODevice::Text))
                return;
        QByteArray strByteArray = ui->textEdit->toPlainText().toUtf8();
        myFile.write(strByteArray);
        myFile.close();
    }
}


void MainWindow::on_action_4_triggered()
{
    fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "/newDoc.txt", tr("myDoc *.txt ;; myDoc *.bin"));

    if(!fileName.isEmpty())
    {
        QFile myFile(fileName);
        if (!myFile.open(QIODevice::WriteOnly | QIODevice::Text))
                return;
        QByteArray strByteArray = ui->textEdit->toPlainText().toUtf8();
        myFile.write(strByteArray);
        myFile.close();
    }
    ui->textEdit->clear();
}

