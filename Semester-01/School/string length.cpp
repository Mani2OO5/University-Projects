#include <iostream>
using namespace std;
int main()
{
    int  length = 0 ;
    string string;
    cout << "enter string: "; cin >> string;
   
while(string[length] != NULL)
{
    length++;
}
cout << length;
}