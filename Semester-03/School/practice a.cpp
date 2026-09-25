#include <iostream>
using namespace std;

class Stack 
{
 private:

    static const int MAX_SIZE = 5;
    int data[MAX_SIZE];
    int TopIndex;

 public:

    Stack() : TopIndex(0) {}
    
    bool empty()
    {
      return TopIndex == 0;
    }

    bool full() 
    {
        return TopIndex == MAX_SIZE - 1;
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
        if (empty()) 
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        TopIndex--;
        
    }

    void printStack() 
    {
        if (TopIndex == 0) 
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

    int TopStack() 
    {
        if (empty()) 
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        
        return data[TopIndex];
    }
};



int main() {}
