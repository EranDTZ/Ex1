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
    
    printf("the Armstrong num are");
    for (int i = min; i <= max; i++)
    {
        if (isArmstrong(i))
        {
            printf(" %d", i);
        }
    }
    printf("\nthe Palindrome num are");
    for (int i = min; i <= max; i++)
    {
        if (isPalindrome(i))
        {
            printf(" %d", i);
        }
    }
    printf("\nthe Prime num are");
    for (int i = min; i <= max; i++)
    {
        if (isPrime(i))
        {
            printf(" %d", i);
        }
    }
    printf("\nthe Strong num are");
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