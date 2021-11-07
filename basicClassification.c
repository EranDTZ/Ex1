#include "NumClass.h"
#include <stdio.h>
#include <math.h>
int isStrong(int x)
{
    int k[10];
    k[0] = 1;
    k[1] = 1;
    for (int i = 2; i < 10; i++)
    {
        k[i] = k[i - 1] * i;
    }
    int a = 0;
    int temp = x;
    while (temp > 0)
    {
        a += k[temp % 10];
        temp /= 10;
    }
    if (a == x)
    {
        return 1;
    }
    return 0;
}

int isPrime(int x)
{
    for (int i = 2; i <= (int)sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }

    return 1;
}
