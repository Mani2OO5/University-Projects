#include <iostream>
using namespace std;

class vector2D
{
    private:
     int X;
     int Y;
    
    public:
     vector2D(int num1 , int num2) : X(num1) , Y(num2) {}
     
     int getX(){ return X; }
     int getY(){ return Y; }
     void show()
     {
        cout << getX() << "i " <<"+ "<< getY() << "j "<<endl;
     }
};

class op 
{
    private : 
     vector2D vector1;
     vector2D vector2;
    public:
     op(vector2D v1 , vector2D v2): vector1(v1) , vector2(v2) {}
     void operator -()
     {
         int YY = vector1.getY() - vector2.getY();
         int XX = vector1.getX() - vector2.getX();
         cout << XX << "i" <<" + "<< YY << "j"<<endl;
     }
     void operator +()
     {
         int YY = vector1.getY() + vector2.getY();
         int XX = vector1.getX() + vector2.getX();
         cout << XX << "i" <<" + "<< YY << "j"<<endl;
     }
     int operator *()
     {
        int sc = vector1.getX()*vector2.getX()+vector1.getY()*vector2.getY();
        cout << sc <<endl;
        return sc;
     } 
     bool operator ==(vector2D H)
     {
       if (vector1.getX()*vector1.getX() + vector2.getX()*vector2.getX() == vector1.getY()*vector1.getY()+vector2.getY()*vector2.getY())
       {
        cout << "ISOMETRIC";
       }
       else if (vector1.getX()*vector1.getX() + vector2.getX()*vector2.getX() > vector1.getY()*vector1.getY()+vector2.getY()*vector2.getY())
       {
        cout << "First one is longer";
       }
       else 
       {
        cout << "seconnd one is longer";
       }
     }
     
     bool operator !=(vector2D H)
     {
        (vector1.getX()*vector1.getX() + vector2.getX()*vector2.getX() == vector1.getY()*vector1.getY()+vector2.getY()*vector2.getY());
        return false;
     }
};
int main()
{
  vector2D vector1(10,5);
  vector2D vector2(2,4);  
  vector1.show();
  vector2.show();

  op O(vector1,vector2);
  -O;
  +O;
  *O;


}