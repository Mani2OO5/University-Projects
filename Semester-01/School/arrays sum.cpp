#include <iostream>
using namespace std;
int main()
{
 short int n;
 int array_1[n] , array_2[n] , array_3[n];

cout << "enter a number of array: "; cin >>n;
 
 for (int i =0 ; i < n ; ++i)
    {
  
     cout << "enter number: " << i + 1 << " of array 1:  "; cin >> array_1[i];
     cout << "enter number: " << i + 1 << " of array 2:  "; cin >> array_2[i];
      
    }
    for (int i =0; i < n ; ++i)
    {
      
      array_3[i] = array_1[i] + array_2[i];
      cout <<  array_3[i] << endl;
    }

}
