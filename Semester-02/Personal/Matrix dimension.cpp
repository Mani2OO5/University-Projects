#include <iostream>
using namespace std;

int main()
{
 short int n;
 cout << "enter matrix dimension: "; cin >> n;
 int matrix[n][n] ;
 int determinant = 0;
 
 

 if ( 1 > n or n > 3)
  return 0;
 
 for (int i = 0 ; i < n ; i++ )
 {
    for (int j = 0 ; j < n ; j++ )
    {
        cout << "matrix element " << i+1 << "-" << j+1 << ":"; cin >> matrix[i][j];
    }
 }
 
 cout << "matrix :" << endl ;


 for (int i = 0 ; i < n ; i++ )
 {
    for (int j = 0 ; j < n ; j++ )
    {
        cout << matrix[i][j] <<  "\t";
    }
    cout << endl;
 }


switch (n)
{
 case 1:

  determinant = matrix[0][0];
  
  break;

  case 2 :

  determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

  break;

  case 3 :

  determinant = (matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1]) 
                 -  
                (matrix[2][0] * matrix[1][1] * matrix[0][2] + matrix[2][1] * matrix[1][2] * matrix[0][0] + matrix[2][2] * matrix[1][0] * matrix[0][1]);
  break;

}
cout <<"determinant: " <<  determinant;



}