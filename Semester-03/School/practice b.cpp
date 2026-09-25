#include <iostream>
using namespace std;

class Stack 
{
 private:

    static const int MAX_SIZE = 5;
    int data[MAX_SIZE];
    int TopIndex;

 public:

    Stack() : TopIndex(-2) {}
    
    bool empty()
    {
        if (TopIndex == -2) {return true;} 
    }

    bool full() 
    {
        if (TopIndex == MAX_SIZE - 1) {return true;}
    }
  
    void push(int value) 
    {
        if (full())
        {
            cout << "Stack is full. Cannot push." << endl;
            return;
        }
        TopIndex++;
        data[TopIndex] = value;
    }

   
    void pop() 
    {
        if (empty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        TopIndex--;
        
    }

    void printStack() 
    {
        if (TopIndex == -2) 
        {
            cout << "Stack is empty." << endl;

            return;
        }

        cout << "Stack: ";

        for (int i = 0; i <= TopIndex; i++) 
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    int TopStack() {return data[TopIndex];}
};



int main() {}

