#include <iostream>
using namespace std;
struct Node
{
    friend class linkedlist;
    int info;
    Node * next , * prev ;
};
class linkedlist
{
    private:
     Node *first;

    public:
     bool empty() {return first == NULL;}

     void addF(int x)
     {  
        Node * p;
        p = new Node;
        p -> prev = NULL;
        p -> next = NULL;

        if (empty())
        {
          first = p;
          return;
        }
        first -> prev = p;
        p -> next = first;
        first = p;
     }

    void addL()
    {
         Node * p , * q;
        p = new Node;
        p -> prev = NULL;
        p -> next = NULL;

        if (empty())
        {
          first = p;
          return;
        }
        q = first;
        while(q -> next != NULL)
         q = q-> next;

        q -> next = p;
        p -> prev = q;
    }

    void addB(int x)
    {
        Node * p , * q;
        p = new Node;
        p -> prev = NULL;
        p -> next = NULL;

        if (empty())
        {
          first = p;
          return;
        }
        q = first;
        while(q -> info -> != y)
         q = q-> next; 

        p -> next = q -> next;
        p -> prev = q;
        q -> next = p;
        q -> next -> prev = p;
    }

    int DelF()
    {
         if (empty())
        {
          cout << "List is empty";
          return -1;
        }
        Node * p;
        p = first;
        first = first -> next;
        first -> prev = NULL;
        int x = p -> info;
        delete p;
        return x;
    }
      int DelL()
    {
         if (empty())
        {
          cout << "List is empty";
          return -1;
        }
        Node * p , * q;
        q = first;
        while(q -> next != NULL)
           q = q -> next;

        p = q -> prev;
        p -> next = NULL;
        int x = q -> info;
        delete q;
        return x;
    }

    int DelB()
    {
         if (empty())
        {
          cout << "List is empty";
          return -1;
        }
        Node * p , * q , * r;
        q = first;
        while(q -> info != y)
           q = q -> next;
         
        p = q -> prev;
        r = q -> next;
        p -> next = r;
        r -> prev = p;
        int x = q -> info;
        delete q;
        return x;
    }
};