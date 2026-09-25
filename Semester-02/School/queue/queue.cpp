#include <iostream>
using namespace std;


class Queue {


 private:
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int frontIndex;
    int rearIndex;

public:
     
    Queue() : frontIndex(-1), rearIndex(-1) {}
    
 
    void enqueue(int value)
    {

        if (rearIndex == MAX_SIZE - 1) 
        {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }


        if (frontIndex == -1) 
        {
            frontIndex = 0;
        }
        rearIndex++;
        data[rearIndex] = value;
    }
 
    void dequeue() 
    {
        if (frontIndex == -1 or frontIndex > rearIndex) 
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        frontIndex++;
    }

     
    void printQueue() 
    {
        if (frontIndex == -1 or frontIndex > rearIndex) 
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";

        for (int i = frontIndex; i <= rearIndex; i++) 
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    

};

int main()
{
    Queue q;
    

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.printQueue();

    q.dequeue();

    q.printQueue();

}