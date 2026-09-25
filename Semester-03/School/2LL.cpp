//2 Linked List

#include <iostream>
using namespace std;
struct Node 
{
    int info;
    Node* next;
    Node* prev;

    Node(int value) : info(value), next(nullptr), prev(nullptr) {}
};



class LinkedList 
{
private:

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void Create(int n) 
    {
        if (n <= 0) return;

        head = new Node(1);
        Node* current = head;

        for (int i = 2; i <= n; i++) 
        {
            Node* newNode = new Node(i);
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
    }

    void Add(int value1, int value2) 
    {
        Node* newNode1 = new Node(value1);
        Node* newNode2 = new Node(value2);

        if (head) 
        {
            newNode2->next = head;
            head->prev = newNode2;
        }
        newNode1->next = newNode2;
        newNode2->prev = newNode1;

        head = newNode1;
    }

    void Remove()
    {
        if (!head or !head->next) return;

        Node* first = head;
        Node* second = head->next;
        head = second->next;

        if (head) head->prev = nullptr;

        delete first;
        delete second;
    }

    void Merge(LinkedList& otherList) 
    {
        if (!head) 
        {
            head = otherList.head;
            return;
        }
        if (!otherList.head) return;

        Node* tail = head;
        while (tail->next) {tail = tail->next;}

        tail->next = otherList.head;
        otherList.head->prev = tail;
        otherList.head = nullptr;
    }

    int Count() const 
    {
        int counter = 0;
        Node* current = head;

        while (current) 
        {
            counter ++;
            current = current->next;
        }
        return count;
    }

    void Print() const 
    {
        Node* current = head;

        while (current) 
        {
            cout << current->info << " ";
            current = current->next;
        }
        cout << endl;
    }
};

