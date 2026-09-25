//Circular List

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

    for (int i = 2; i <= n; i++) 
    {
        current->next = new Node{i, nullptr};
        current = current->next;
    }
    
    current->next = head;
    return head;
}

Node* merge(Node* f1, Node* f2) 
{
    if (!f1 or !f2) 

     return NULL;

    Node* temp1 = f1;

    while (temp1->next != f1) 
     
     temp1 = temp1->next;

    Node* temp2 = f2;

    while (temp2->next != f2) 
    
     temp2 = temp2->next;

    temp1->next = f2;
    temp2->next = f1;
    
    return f1;
}

void print(Node* head) 
{
    if (!head) return;

    Node* current = head;

    do 
    {
       cout << current->info << " -> ";
       current = current->next;
    } while (current != head);

    cout << "(Circular)" << endl;
}

int main() {
    Node* f1 = create(3);
    Node* f2 = create(2);
    f1 = merge(f1, f2);
    print(f1);
    return 0;
}

