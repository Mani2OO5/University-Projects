#include <iostream>
using namespace std;

int main()
{
  short int n;
  int array[n] , sum = 0;

  cout << " please enter number of array: "; cin >> n ;
  
 for (int i =0 ; i < n ; ++i)
    {
  
     cout << "enter number: " << i + 1 << " of array:  "; cin >> array[i];
     if ( array[i] % 2 == 0)
      sum += array[i];

    }
    cout<<sum;
  

}د