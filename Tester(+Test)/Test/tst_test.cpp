#include <QtTest>
#include <QCoreApplication>
#include "../Prak1/MainFunc.cpp"
#include "header/xlsxdocument.h"
#include "header/xlsxworkbook.h"
using namespace QXlsx;
// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void test_col();
    void test_row();
    void test_write();
    void test_read();
};

test::test()
{

}

test::~test()
{

}

void test::test_write()
{
    SetValueByIndex("test", "5", 1, 1);
    QCOMPARE(GetValueByIndex("test", 1, 1), "5");
}
void test::test_read()
{
    QCOMPARE(GetValueByIndex("test", 1, 1), "5");
}

void test::test_row()
{
    QCOMPARE(rowAmount("test3"), 3);
}

void test::test_col()
{
    QCOMPARE(colAmount("test3"), 3);
}

QTEST_MAIN(test)

#include "tst_test.moc"
