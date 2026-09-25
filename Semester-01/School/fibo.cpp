#include <iostream>

int fibo(int n)
{   
    int counter = 0;
    if (counter == n) return 0;

    
    int member = counter + fibo(counter);
    std:: cout << member << " ";
    counter++;

    return member;
}
int main()
{
    fibo(10);
}