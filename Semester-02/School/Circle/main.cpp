#include <iostream>
#include "circleclass.cpp"
using namespace std;

int main()
{

    Circle c1(5 , "blue");
    Circle c2(10 , "red"); 


    cout << "Circle 1: ";
    c1.printInfo();
    cout << "Circle 2: ";
    c2.printInfo();

    cout << "area of circle 1 : " << c1.getArea() << endl
         << "Circumference of circle 1 : " << c1.getCircumference()<< endl;
    
    cout << "area of circle 1 : " << c2.getArea() << endl
         << "Circumference of circle 1 : " << c2.getCircumference()<< endl;


    if (c1 == c2) {
        cout << "The colors of the circles are the same." << endl;
    } else {
        cout << "The colors of the circles are different." << endl;
    }

    return 0;



}