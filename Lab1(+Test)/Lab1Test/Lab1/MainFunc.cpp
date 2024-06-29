#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int FindLastNumber(int Kn)
{
    unsigned long long num(1);
    unsigned long long numCopy;
    unsigned long long sum;
    unsigned long long i;
    unsigned long long K;
    K=Kn;
    K++;
    int resultNum = 0;
    while (num < K)
    {
        sum = 0;
        i = 1;
        numCopy = num;
        while (numCopy)
        {
            sum += numCopy % 10;
            numCopy /= 10;
        }
        if (sum != 1)
            while (pow(sum, i) <= num)
            {
                if (pow(sum, i) == num)
                {
                    cout << sum << i << "=" << num << endl;
                    resultNum = num;
                    break;
                }
                i++;
            }
        num++;
    }
    return resultNum;
}
