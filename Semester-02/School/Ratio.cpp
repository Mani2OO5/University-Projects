#include <iostream>
using namespace std;

class Ratio
{
  private:
   
    int num , den;
  
  public:
     Ratio(int, int);
    void get(int , int );
    void print();
    void reverse();
};
void Ratio:: get(int a , int b) { num = a , den = b;}
void Ratio:: print(){cout << num << "/" << den;}
void Ratio:: reverse()
{
    int temp = num;
         num = den;
         den = temp;
}
Ratio:: Ratio(int c , int d): num(c) , den(d) {}



int main()
{
    Ratio fraction(0,1) , foo = fraction;
    boobs.print();
    cout << endl;
    fraction.reverse();
    cout << endl;
    fraction.print();
    cout << endl;
     fraction.get(6,7);
    fraction.print();
    cout << endl;
    fraction.reverse();
    cout << endl;
    fraction.print();
}