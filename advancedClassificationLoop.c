#include "NumClass.h"
#include <math.h>
#include <stdio.h>

int isArmstrong(int x)
{
   int caunt = 0;
   int zero = 0;
   int temp = x;
   while (temp > 0)
   {
      zero = temp % 10;
      temp /= 10;
      caunt++;
   }
   int a = 0;
   temp = x;
   for (int i = 0; i < caunt; i++)
   {
      zero += pow(temp % 10, caunt);
      temp /= 10;
   }
   if (zero == x)
   {
      return 1;
   }

   return 0;
}
int isPalindrome(int x)
{
   int caunt = 0;
   int zero = 0;
   int temp = x;
   while (temp > 0)
   {
      zero = temp % 10;
      temp /= 10;
      caunt++;
   }
   int k[caunt];
   for (int i = 0; i < caunt; i++)
   {
      k[i] = x % 10;
      x /= 10;
   }
   for (int i = 0; i < caunt; i++)
   {
      if (k[i] != k[caunt - i - 1])
         return 0;
   }
   return 1;
}
