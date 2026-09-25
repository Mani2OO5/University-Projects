#include <iostream>
using namespace std;

struct Node 
{
  friend class linkedlist;
  int   info;
  Node *next;
};
class linkedList
{ Node * q , *p ;
    q = first;

 public:
  linkedList(): first(NULL) {}
  bool empty() { return first == NULL;}

  void addF(int x)
  {
    Node * p;
    p = new Node;
    p -> info = x;
    p -> next = NULL;
    if(empty())
    {
      first = p;
      return;
    }
    
    p -> next = first;
    first = p;
  }
  void addL(int x)
  {
    Node *p;
    p = new Node;
    p -> next = NULL;
    p -> info = x;
    if(empty())
    {
        first = p;
        return;
    }
    Node * q;
    q = first;
    while (q -> next != NULL)
      q = q -> next;

    q -> next = p;
    

  } 
  
  void addB(int x)
  {
     Node *p;
     p = new Node;
     p -> info = x; 
     p -> next = NULL;
     
     if(empty())
    {
        first = p;
        return;
    }
    Node *q;
    q = first;
    while(q -> next -> info != y)
     q = q -> next;

    q -> next = p -> next;
    q -> next = p;

  }
 
 int DelF()
 {
    if(empty())
    {
        cout << "List is empty";
        return -1;
    }
    Node *p;
    p = first;
    first = first ->next;
    int x = p -> info;
    delete p;
    return x;

 }
 int DelL()
 {
    if(empty())
    {
        cout << "List is empty";
        return -1;
    }
    Node * q , *p ;
    q = first;
    while(q -> next -> next  != NULL)
       q = q -> next;

    p = q -> next;
    q -> next = NULL;
    int x = p -> info;
    delete p;
    return x;
 }

 int DelB()
 {   
    if(empty())
    {
        cout << "List is empty";
        return -1;
    }
     Node * q , *p ;
    q = first;
    while(q -> next -> info != y)
       q = q -> next;
    p = q -> next;
    q -> next = p -> next;
    delete p;
 }

};