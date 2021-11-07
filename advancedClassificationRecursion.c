#include "NumClass.h"
#include <math.h>
#include <stdio.h>
int calcArmstrong(int x, int numofdigit)
{
    if (x < 10)
    {
        return pow(x, numofdigit);
    }

    int temp = (int)pow(x % 10, numofdigit);
    return temp + calcArmstrong(x / 10, numofdigit);
}
int isArmstrong(int x)
{
    if (x < 0)
    {
        return 0;
    }
    int numofdigit = (int)log10(x) + 1;
    if (x != calcArmstrong(x, numofdigit))
    {
        return 0;
    }
    return 1;
}

int calcPalindrome(int x)
{
    int temp = (int)log10(x);
    if (x < 10)
    {
        return x;
    }
    return (((x % 10) * pow(10, temp)) + calcPalindrome(x / 10));
}
int isPalindrome(int x)
{
    if (x != calcPalindrome(x))
    {
        return 0;
    }
    return 1;
}
