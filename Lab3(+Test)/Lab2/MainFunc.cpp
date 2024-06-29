int FindMax(int M)
{
    int max(0);
    int min(1000);
    int num1;
    int num2;
    int num3;
    int i;
    int j;
    int k;
    for (int num = 100; num < 1000; num++)
    {
        num1 = num % 10;
        i = num1;
        num1 *= i * i;

        num2 = (num / 10) % 10;
        j = num2;
        num2 *= j * j;

        num3= (num / 100) % 10;
        k = num3;
        num3 *= k * k;

        if (num1 + num2 + num3 == M)
        {
            if (num > max)
                max = num;
            if (num < min)
                min = num;
        }
    }
    return max;
}

int FindMin(int M)
{
    int max(0);
    int min(1000);
    int num1;
    int num2;
    int num3;
    int i;
    int j;
    int k;
    for (int num = 100; num < 1000; num++)
    {
        num1 = num % 10;
        i = num1;
        num1 *= i * i;

        num2 = (num / 10) % 10;
        j = num2;
        num2 *= j * j;

        num3= (num / 100) % 10;
        k = num3;
        num3 *= k * k;

        if (num1 + num2 + num3 == M)
        {
            if (num > max)
                max = num;
            if (num < min)
                min = num;
        }
    }
    return min;
}
