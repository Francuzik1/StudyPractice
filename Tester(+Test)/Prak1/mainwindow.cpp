#include "mainwindow.h"
#include "MainFunc.cpp"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QString>
#include <QDir>
#include <qaxobject.h>
#include "header/xlsxdocument.h"
#include "header/xlsxworkbook.h"
using namespace QXlsx;
int colG;
int rowG;
QStandardItemModel* model=  new QStandardItemModel(1, 1);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // QStandardItemModel* model=  new QStandardItemModel(row, col);
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//columns
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}

//rows
void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{

}


void MainWindow::on_lineEdit_3_textEdited(const QString &arg1)
{

}


void MainWindow::on_pushButton_clicked()
{
    int row = 1; int col = 1;
    Document xlsxR(ui->lineEdit_3->text() + ".xlsx");

    if (xlsxR.load()) // load excel file
    {
        Cell* cell = xlsxR.cellAt(row, col);        // get cell pointer.
        while(cell!=nullptr)
        {
            cell=xlsxR.cellAt(++row,1);
        }
        row--;
        cell=xlsxR.cellAt(1,1);
        while(cell!=nullptr)
        {
            cell=xlsxR.cellAt(1,++col);
        }
        col--;
        model=new QStandardItemModel(row,col);
        ui->tableView->setModel(model);
        for(int i=0; i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cell=xlsxR.cellAt(i+1,j+1);
                QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
                model->setItem(i,j, new QStandardItem(var.toString()));
            }
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    int col = ui->tableView->size().width();
    int row = ui->tableView->size().height();
    QXlsx::Document xlsx;
    for (int i = 1; i < row+1; i++)
    {
        for (int j = 1; j < col+1; j++)
        {
            QModelIndex index = model->index(i-1,j-1,QModelIndex());
            xlsx.write(i, j,model->data(index,0).toString());
        }
    }
    xlsx.saveAs(ui->lineEdit_3->text() + ".xlsx");
    return;
}


void MainWindow::on_pushButton_3_clicked()
{
    int row = 1;
    int col = 1;
    int colS = model->columnCount();
    int rowS = model->rowCount();

    QString** elems = new QString*[rowS];
    for (int i =0; i < rowS; i++)
    {
        elems[i] = new QString[colS];
    }
    for (int i = 0; i < rowS; i++)
    {
        for (int j = 0; j < colS; j++)
        {
            QModelIndex index = model->index(i,j,QModelIndex());
            elems[i][j] = model->data(index,0).toString();
        }
    }
    if (ui->lineEdit->text().toInt())
    {
        col = ui->lineEdit->text().toInt();
    }
    if (ui->lineEdit_2->text().toInt())
    {
        row = ui->lineEdit_2->text().toInt();
    }
    model=  new QStandardItemModel(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            model->setItem(i, j, new QStandardItem(elems[i][j]));
        }
    }
    ui->tableView->setModel(model);
}

