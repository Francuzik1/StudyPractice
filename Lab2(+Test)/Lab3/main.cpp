#include <iostream>
using namespace std;

int main (){
    unsigned long long number;
    unsigned long long numberNow;
    unsigned long long N;
    unsigned long long j;
    cin >> N;
    for (unsigned long long i(10); i < N; i++)
    {
        numberNow = i;
        number = 0;
        j = 1;
        while (numberNow)
        {
            if (numberNow % 10)
                number += (numberNow % 10) * (j);
            j *= 100;
            numberNow /= 10;
        }
        if ((number % i) == 0)
            cout << number << " " << number / i << " " << i << endl;
    }
}
