#include <iostream>
using namespace std;

int main(){
    long double num1, num2;
    char op;
    cout << "enter first number: ";  cin >> num1;
    cout << "enter second number: "; cin >> num2;
    cout << "enter operatator: ";    cin >> op;
    switch(op){
        case '+':
        cout << num1 + num2;
         break;
         case '-':
        cout << num1 - num2;
         break;
         case '*':
        cout << num1 * num2;
         break;
         case '/':
        cout << num1 / num2;
         break;
    }

}
