#include <iostream>
using namespace std;

class Stack
{
    private:
     static const int MaxSize = 100;
     int data[MaxSize];
     int TopIndex;

    public:
     
     Stack(): TopIndex(-1) {}

     void Push(int Num)
      {
       if (TopIndex == MaxSize -1){ return; }
       TopIndex ++;
       data[TopIndex] = Num;
      }
     void Pop()
      {
        if (TopIndex ==-1){ return; }
        TopIndex --;
      }

     void PrintStack()
     {
        if (TopIndex ==-1){ return; }
        for(int i = 0 ; i <= TopIndex ; i ++ )
        {
            cout << data[i] << " ";
        }
        cout << endl;
     }
     
};
int main()
{
    
    Stack S;

    S.Push(1);
    S.Push(2);
    S.Push(3);
    S.Push(4);
    S.Push(5);
    S.PrintStack();
    S.Pop();
    S.PrintStack();
    S.Pop();
    S.PrintStack();
    S.Pop();
    S.PrintStack();
    S.Pop();
    S.PrintStack();
    S.Pop();
    S.PrintStack();

}