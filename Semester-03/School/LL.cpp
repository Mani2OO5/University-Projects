//List
#include <iostream>
using namespace std;


struct Node 
{
    int info;
    Node* next;
};


Node* create(int n) 
{
    if (n <= 0) return nullptr;

    Node* head = new Node{1, nullptr};
    Node* current = head;

    for (int i = 2; i <= n; ++i) 
    {
        current->next = new Node{i, nullptr};
        current = current->next;
    }

    return head;
}


Node* addTwo(Node* head, int x1, int x2)
 {
    Node* node1 = new Node{x1, head};
    Node* node2 = new Node{x2, node1};
    return node2;
}


Node* merge(Node* f1, Node* f2) 
{
    if (!f1 or !f2) 

     return NULL;


    Node* current = f1;
    while (current->next) 
    {
        current = current->next;
    }
    current->next = f2;

    return f1;
}


int count(Node* head) 
{
    int count = 0;
    while (head) {
        ++count;
        head = head->next;
    }
    return count;
}

Node* reverse(Node* head) 
{
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


void print(Node* head) 
{
    while (head) 
    {
        cout << head->info << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}
