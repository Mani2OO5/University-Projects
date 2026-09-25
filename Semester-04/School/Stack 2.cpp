#include <iostream>
using namespace std;

class Stack
{
    private:
     
     static const int Max = 100;
                  int stack[Max];
                  int Top;

    public:
     Stack() : Top(-1) {}

     bool empty() { return Top == -1; }
     bool full()  { return Top == Max -1; }

    void Push(int x)
    {
        if(full())

          cout << "stack is full";
          return;
          
        Top ++;
        stack[Top] = x ;

    }

    int Pop()
    {
      if(empty())
      
        cout << "stack is empty";
        return -1;

       
       int x = stack[Top];
       Top --;
       return x;

      
    }
};