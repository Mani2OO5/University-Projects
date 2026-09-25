#include <iostream>
using namespace std;
struct Node
{
    friend class linkedS;
    friend class linkedQ;
    int info;
    Node * next;
};
class linkedS
{
  private:
   Node * Top;
  public:
   linkedS(): Top(NULL){}
   bool empty(){return Top == NULL;}
   
   void push(int x)
   {
    Node *p;
    p = new Node;
    p -> next = NULL;
    p -> info = x;
    if (empty())
    {
        Top = p;
        return;
    }
    p -> next = Top;
    Top = p;

   }
   
   int pop()
   {
    if (empty())
    {
        cout << "stack is empty";
        return -1;
    }
    Node *p;
    p = Top;
    Top = Top -> next; 
    int x = p -> info;
    delete p;
    return x;

   }
};
class linkedQ
{
  private:
   Node * rear , * front;
  public:
   linkedQ(): rear(NULL) , front(NULL){}
   bool empty(){return rear == NULL or front == NULL;}

   void add(int x)
   {
    Node *p;
    p = new Node;
    p -> next = NULL;
    p -> info = x;
    if (empty())
    {
        p = rear = front;
        return;
    }
    rear -> next = p;
    rear = p;
     
   }
   
   int Del()
   {
    if(empty())
    {
        cout << "queue is empty";
        retrun -1;
    }
    Node *p;
    p = front;
    front = front -> next;
    int x = p -> info;
    delete p;
    return x;
   }
};