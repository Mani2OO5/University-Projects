#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


class Car {
private:
    string name;
    string color;
    double speed;
    double fuelCapacity;
    int passengerCapacity;

public:
   
    Car(string n,string c, double s) : name(n),color(c), speed(s) {}

   
    string GetName()   {return name;}

    string GetColor()  {return color;}

    double GetSpeed()  {return speed;}
    
    void display()  
    {
        cout << "Name: "  << name  << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Color:"  << color << endl;
    }
   
   void operator ==(Car other) 
   {    
     if(color == other.color)
     {cout << "both cars arre : " << GetColor();}
    
     else
     { 
        cout << "these cars have diffrent colors \n"
             <<"First Car is " << GetColor()
             << " and second car is " << GetColor() << endl;
               
     }
    }
   
   void operator =(Car other) 
   {
    if (speed > other.speed) {cout << "the first car is faster \n";}
    else if (speed < other.speed) {cout << "the second car is faster \n";}
    else{ cout << "the first cars speed is as fast as the second car \n";}
   }
   
    
};

int main() 
{
    
    Car car1("Car A","red", 180 );
    Car car2("Car B","blue", 200);
    Car car3 = car1;

    cout << "Details of Car 1:" << endl;
    car1.display();
    cout << endl;

    cout << "Details of Car 2:" << endl;
    car2.display();
    cout << endl;
    cin.get();
    (car1 = car3);
    (car1 == car2);
    return 0;


}
 
