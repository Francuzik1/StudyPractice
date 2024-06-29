#include <QtTest>
#include "../Lab3/MainFunc.cpp"
// add necessary includes here

class TestNum : public QObject
{
    Q_OBJECT

public:
    TestNum();
    ~TestNum();

private slots:
    void test_num();
};

TestNum::TestNum() {}

TestNum::~TestNum() {}

void TestNum::test_num()
{
    QCOMPARE(FindLastNumber(10), 10);
    QCOMPARE(FindLastNumber(20), 20);
    QCOMPARE(FindLastNumber(49), 45);
    QCOMPARE(FindLastNumber(230), 222);
    QCOMPARE(FindLastNumber(290), 285);
    QCOMPARE(FindLastNumber(119999), 119817);
    QCOMPARE(FindLastNumber(707150), 707070);
    QCOMPARE(FindLastNumber(12280000), 12274935);
}

QTEST_APPLESS_MAIN(TestNum)

#include "tst_testnum.moc"
