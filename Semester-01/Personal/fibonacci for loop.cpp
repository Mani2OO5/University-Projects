//fibonacci with for loop
#include <iostream>
using namespace std;
int main(){
 int n , num1 = 0, num2 = 1, next_number = 1;
  cout<<"enter a number: ";
   cin>>n;
 for(int i = 1;i < (n);i++){
  cout<<next_number<<" ";
   num1 = num2;
    num2 = next_number;
    next_number = num1 + num2;
 }
 return 0;
}
