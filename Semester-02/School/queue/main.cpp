#include <iostream>
#include "queue.cpp"
using namespace std;

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
    
