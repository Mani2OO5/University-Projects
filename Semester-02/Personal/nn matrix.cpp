#include <iostream>
using namespace std;

int main(){
   short int n; 
   double matrix[n][n];
    
    cout << "please insert matrix dimension: "; cin >> n;
    
    for(int i = 1; i <= n; ++i){
        
        for(int j =1; j <= n; ++j){
            
            cout << "Matrix element " << i << "-" << j << ": "; cin >> matrix[i][j];
        }
    }

    cout << "\bit's your matrix: \b" << endl;

    for(int i = 1; i <= n; ++i){
        
        for(int j =1; j <= n; ++j){
            
            cout <<  matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
   long double determinant;

   for(int k = 1 ;k <= n; ++k ){
    
   }

}