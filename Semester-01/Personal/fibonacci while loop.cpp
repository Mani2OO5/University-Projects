//fibonacci with wile loop
#include <iostream>
using namespace std;
int main(){
 int n, num1 = 0, num2 =1, next_number = 1, count = 1; 
 while(count <= n){
    cout<<next_number<<" ";
    count+=1;
    num1=num2;
    num2=next_number;
 next_number=num1 +num2;
  }

 return 0;
}