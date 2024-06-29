#include <QtTest>
#include "../Lab2/MainFunc.cpp"
// add necessary includes here

class test_nums : public QObject
{
    Q_OBJECT

public:
    test_nums();
    ~test_nums();

private slots:
    void test_min();
    void test_max();
};

test_nums::test_nums() {}

test_nums::~test_nums() {}

void test_nums::test_min()
{
    QCOMPARE(FindMin(532), 457);
    QCOMPARE(FindMin(737), 209);
    QCOMPARE(FindMin(640), 448);
    QCOMPARE(FindMin(855), 159);
    QCOMPARE(FindMin(133), 205);
}

void test_nums::test_max()
{
    QCOMPARE(FindMax(532), 754);
    QCOMPARE(FindMax(737), 920);
    QCOMPARE(FindMax(640), 844);
    QCOMPARE(FindMax(855), 951);
    QCOMPARE(FindMax(133), 520);
}

QTEST_APPLESS_MAIN(test_nums)

#include "tst_test_nums.moc"
