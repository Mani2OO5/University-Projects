#include <iostream>
using namespace std;

class Stack {
private:

    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

  
    void push(int value) {
        if (topIndex == MAX_SIZE - 1) {
            cout << "Stack is full. Cannot push." << endl;
            return;
        }
        topIndex++;
        data[topIndex] = value;
    }

   
    void pop() {
        if (topIndex == -1) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        topIndex--;
        

    void printStack() 
    {
        if (topIndex == -1) 
        {
            cout << "Stack is empty." << endl;

            return;
        }

        cout << "Stack: ";

        for (int i = 0; i <= topIndex; i++) 
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    double topstack()
    {
    return topIndex;
    }
};



int main() 
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.printStack();

    s.pop();

    s.printStack();

    s.topstack();

    return 0;


}
