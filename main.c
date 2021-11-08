#include <stdio.h>
#include "NumClass.h"
#include "basicClassification.c"
#include "advancedClassificationRecursion.c"


int main()
{
    int max, min;
    do
    {
        scanf("%d %d", &min, &max);
    } while (min<=0 || max<=0);
    
    printf("The Armstrong numbers are:");
    for (int i = min; i <= max; i++)
    {
        if (isArmstrong(i))
        {
            printf(" %d", i);
        }
    }
    printf("\nThe Palindromes are:");
    for (int i = min; i <= max; i++)
    {
        if (isPalindrome(i))
        {
            printf(" %d", i);
        }
    }
    printf("\nThe Prime numbers are:");
    for (int i = min; i <= max; i++)
    {
        if (isPrime(i))
        {
            printf(" %d", i);
        }
    }
    printf("\nThe Strong numbers are:");
    for (int i = min; i <= max; i++)
    {
        if (isStrong(i))
        {
            printf(" %d", i);
        }
    }
    printf("\n");
    return 0;
}
