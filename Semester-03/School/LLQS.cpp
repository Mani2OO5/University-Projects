void stack::push(int x, int y) 
{
    node *p1 = new node;
    node *p2 = new node;

    p1->info = x;
    p1->next = top;
    top = p1;

    p2->info = y;
    p2->next = top;
    top = p2;
}

void stack::pop(int &x1, int &x2, int &underflow) 
{
    node *p;

    underflow = 0;
    if (empty() || top->next == nullptr) 
    {
        underflow = 1;
        cout << "stack does not have enough elements";
        return;
    }

    p = top;
    x1 = p->info;
    top = top->next;
    delete p;

    p = top;
    x2 = p->info;
    top = top->next;
    delete p;
}
void queue::addq(int x1, int x2) 
{
    node *p1 = new node;
    node *p2 = new node;

    p1->info = x1;
    p1->next = nullptr;

    p2->info = x2;
    p2->next = nullptr;

    if (front == nullptr) 
    {
        front = p1;
        rear = p1;
        rear->next = p2;
        rear = p2;
    } else {
        rear->next = p1;
        rear = p1;
        rear->next = p2;
        rear = p2;
    }
}

void queue::delq(int &x1, int &x2) {
    if (front == nullptr || front->next == nullptr) {
        cout << "Queue does not have enough elements";
        return;
    }

    node *p;

    p = front;
    x1 = p->info;
    front = front->next;
    delete p;

    p = front;
    x2 = p->info;
    front = front->next;
    delete p;

    if (front == nullptr) {
        rear = nullptr;
    }
}
