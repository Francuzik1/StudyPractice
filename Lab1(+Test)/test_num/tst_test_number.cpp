#include <QCoreApplication>
#include <QtTest>
#include "../Lab1/MainFunc.cpp"
// add necessary includes here

class test_number : public QObject
{
    Q_OBJECT

public:
    test_number();
    ~test_number();

private slots:
    void TestLastNumber();
};

test_number::test_number() {}

test_number::~test_number() {}

void test_number::TestLastNumber()
{
    QCOMPARE(FindLastNumber(8), 8);
    QCOMPARE(FindLastNumber(9), 9);
    QCOMPARE(FindLastNumber(100), 81);
    QCOMPARE(FindLastNumber(600), 512);
    QCOMPARE(FindLastNumber(3000), 2401);
    QCOMPARE(FindLastNumber(5000), 4913);
    QCOMPARE(FindLastNumber(20000), 19683);
    QCOMPARE(FindLastNumber(235000), 234256);
}

QTEST_MAIN(test_number)

#include "tst_test_number.moc"

