#include <QStandardItemModel>
#include <QString>
#include <QDir>
#include "header/xlsxdocument.h"
#include "header/xlsxworkbook.h"

using namespace QXlsx;

QString GetValueByIndex(QString fileName, int i, int j)
{
    Document xlsxR(fileName + ".xlsx");
    Cell* cell = xlsxR.cellAt(i, j);
    QVariant var = cell->readValue();
    return var.toString();
}

void SetValueByIndex(QString FileName, QString value, int i, int j)
{
    Document xlsx;
    xlsx.write(i, j,value);
    xlsx.saveAs(FileName + ".xlsx");
    return;
}

int rowAmount(QString fileName)
{
    Document xlsxR(fileName + ".xlsx");
    int row = 1; int col = 1;
    QXlsx::Cell* cell = xlsxR.cellAt(row, col);        // get cell pointer.
    while(cell!=nullptr)
    {
        cell=xlsxR.cellAt(++row,1);
    }
    row--;
    return row;
}

int colAmount(QString fileName)
{
    Document xlsxR(fileName + ".xlsx");
    int row = 1; int col = 1;
    Cell* cell = xlsxR.cellAt(row, col);;
    while(cell!=nullptr)
    {
        cell=xlsxR.cellAt(1,++col);
    }
    col--;
    return col;
}
