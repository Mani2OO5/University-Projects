#include <iostream>
using namespace std;

int main()
{
    int i = 1, num, fact = 1;
    
    cout << "enter number: "; cin >>num;
    
    for (i ; i <= num ; ++i)
    {
        fact*=i;
    }
    
    cout <<"factorial: "<< fact ;
}
