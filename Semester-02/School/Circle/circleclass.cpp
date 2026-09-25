#include <iostream>
#include <string>

using namespace std;


class Circle
{
  private:
    double radius;
    string color;

  public:
    
    Circle(double r = 1.0, string c = "red") : radius(r), color(c) {}
  
    double getRadius()  {return radius;}

    void setRadius(double r) {radius = r;}

    string getColor() {return color;}

    void setColor(string c) {color = c;}
     
    double getArea() {return 3.14 * radius * radius;}
    
    double getPrimeter() {return 2 * 3.14 * radius;}

    void operator ==(Circle other) 
    { 
        if(color == other.color) {cout << "Both are " << color << endl;}
        else {cout << "their colors are diffrent";}
    }

    void printInfo() {cout << "Radius: " << radius << ", Color: " << color << endl;}
  
};
int main()
{

    Circle c1(5 , "blue");
    Circle c2(10 , "red");
    Circle c3(c2); 


    cout << "Circle 1: ";
    c1.printInfo();
    cout << "Circle 2: ";
    c2.printInfo();

    cout << "area of circle 1 : " << c1.getArea() << endl
         << "Primeter of circle 1 : " << c1.getPrimeter()<< endl;
    
    cout << "area of circle 1 : " << c2.getArea() << endl
         << "Primeter of circle 1 : " << c2.getPrimeter()<< endl;
    
    c2 == c3;

    return 0;
}

