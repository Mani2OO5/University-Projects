//ASCII input
#include "iostream"
#include "conio.h"
int main()
{
unsigned char ch;
ch= getch();
printf("%d",ch);
if(!ch)
{
   ch=getch();
   printf("%d",ch);
}
}