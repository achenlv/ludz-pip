#include <iostream>

// The values should be whole non-negative numbers!!!
// Coded by: Prof. G. Arnicāns


using namespace std;

class StackArray {
private:
    int* table;
    int length;
    int size;
public:
    StackArray(int maxElementCount);
    ~StackArray();
    int isEmpty();
    int top();
    int push(int value);
    int pop();
};

class QueueArray {
private:
    int* table;
    int front;
    int length;
    int size;
public:
    QueueArray(int maxElementCount);
    ~QueueArray();
    int isEmpty();
    int first();
    int enqueue(int value);
    int dequeue();
};

class StackList {
private:
    struct Node;
    struct Node {
        int info;
        Node* next;
    };

    Node* topNode;

public:
    StackList();
    ~StackList();
    int isEmpty();
    int top();
    int push(int value);
    int pop();
};

class QueueList {
private:
    struct Node;
    struct Node {
        int info;
        Node* next;
    };

    Node* front;
    Node* back;

public:
    QueueList();
    ~QueueList();
    int isEmpty();
    int first();
    int enqueue(int value);
    int dequeue();
};

void testStackArray(void);
void testQueueArray(void);
void testStackList(void);
void testQueueList(void);

int main()
{
    testStackArray();
    testQueueArray();
    testStackList();
    testQueueList();

    return 0;
}

//------------ StackArray ------------

StackArray::StackArray(int maxElementCount) {
    if (maxElementCount < 1)
        maxElementCount = 1;  // at least one element can be stored
    table = new int[maxElementCount];
    length = 0;
    size = maxElementCount;
}

StackArray::~StackArray() {
    delete[] table;
}

int StackArray::isEmpty() {
    return length == 0;
}

int StackArray::top() {
    if (isEmpty())
        return -1; // Error, Stack is empty
    return table[length - 1];
}

int StackArray::push(int value) {
    if (length == size)
        return -1; // Error, Stack is full
    table[length++] = value;
    return 0; // OK, element is stored
}

int StackArray::pop() {
    if (isEmpty())
        return -1; // Error, Stack is empty
    return table[--length];
}

//------------ QueueArray ------------

QueueArray::QueueArray(int maxElementCount) {
    if (maxElementCount < 1)
        maxElementCount = 1;  // at least one element can be stored
    table = new int[maxElementCount];
    front = 0;
    length = 0;
    size = maxElementCount;
}

QueueArray::~QueueArray() {
    delete[] table;
}

int QueueArray::isEmpty() {
    return length == 0;
}

int QueueArray::first() {
    if (isEmpty())
        return -1; // Error, Queue is empty
    return table[front];
}

int QueueArray::enqueue(int value) {
    if (length == size)
        return -1; // Error, Queue is full
    table[(front + length++) % size] = value;
    return 0; // OK, element is stored
}

int QueueArray::dequeue() {
    if (isEmpty())
        return -1; // Error, Queue is empty
    int value = table[front];
    length--;
    front = (front + 1) % size;
    return value;
}

//------------ StackList ------------

StackList::StackList() {
    topNode = 0;
}

StackList::~StackList() {
    Node* delNode;
    while (topNode) {
        delNode = topNode;
        topNode = topNode->next;
        delete delNode;
    }
}

int StackList::isEmpty() {
    return topNode == 0;
}

int StackList::top() {
    if (isEmpty())
        return -1; // Error, Stack is empty
    return topNode->info;
}

int StackList::push(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = topNode;
    topNode = newNode;

    return 0; // OK, element is stored
}

int StackList::pop() {
    if (isEmpty())
        return -1; // Error, Stack is empty
    int value = topNode->info;
    Node* delNode = topNode;
    topNode = topNode->next;
    delete delNode;

    return value;
}

//------------ QueueList ------------

QueueList::QueueList() {
    front = 0;
    back = 0;
}

QueueList::~QueueList() {
    Node* delNode;
    while (front) {
        delNode = front;
        front = front->next;
        delete delNode;
    }
}

int QueueList::isEmpty() {
    return front == 0;
}

int QueueList::first() {
    if (isEmpty())
        return -1; // Error, Queue is empty
    return front->info;
}

int QueueList::enqueue(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = 0;
    if (front == 0)
        front = newNode;
    else
        back->next = newNode;
    back = newNode;

    return 0; // OK, element is stored
}

int QueueList::dequeue() {
    if (isEmpty())
        return -1; // Error, Queue is empty
    int value = front->info;
    Node* delNode = front;
    front = front->next;
    delete delNode;
    if (front == 0)
        back = 0;

    return value;
}

//------------ Testing ------------


void testStackArray(void) {
    cout << "----- Start of StackArray testing" << endl;
    StackArray stack(10);

    if (stack.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    for (int i = 0; i < 11; i++) {
        stack.push(i);
        cout << "Top value is " << stack.top() << endl;
    }

    if (stack.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    while (!stack.isEmpty())
        cout << "Taken out value is " << stack.pop() << endl;

    if (stack.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    cout << "----- End of StackArray testing" << endl << endl;
}

void testQueueArray(void) {
    cout << "----- Start of QueueArray testing" << endl;
    QueueArray queue(10);

    int i;

    if (queue.isEmpty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    for (i = 0; i < 8; i++)
        queue.enqueue(i);

    if (queue.isEmpty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    for (i = 0; i < 5; i++)
        cout << "Taken out value is " << queue.dequeue() << endl;

    if (queue.isEmpty())
        cout << "Queue is empty" << endl;
    else {
        cout << "Queue is not empty" << endl;
        cout << "The first value is " << queue.first() << endl;
    }

    for (i = 8; i < 20; i++)
        queue.enqueue(i);

    while (!queue.isEmpty())
        cout << "Taken out value is " << queue.dequeue() << endl;

    if (queue.isEmpty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    cout << "----- End of QueueArray testing" << endl << endl;
}

void testStackList(void) {
    cout << "----- Start of StackList testing" << endl;
    StackList stack;

    if (stack.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    for (int i = 0; i < 11; i++) {
        stack.push(i);
        cout << "Top value is " << stack.top() << endl;
    }

    if (stack.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    while (!stack.isEmpty())
        cout << "Taken out value is " << stack.pop() << endl;

    if (stack.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    cout << "----- End of StackList testing" << endl << endl;
}

void testQueueList(void) {
    cout << "----- Start of QueueList testing" << endl;
    QueueList queue;

    int i;

    if (queue.isEmpty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    for (i = 0; i < 8; i++)
        queue.enqueue(i);

    if (queue.isEmpty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    for (i = 0; i < 5; i++)
        cout << "Taken out value is " << queue.dequeue() << endl;

    if (queue.isEmpty())
        cout << "Queue is empty" << endl;
    else {
        cout << "Queue is not empty" << endl;
        cout << "The first value is " << queue.first() << endl;
    }

    for (i = 8; i < 20; i++)
        queue.enqueue(i);

    while (!queue.isEmpty())
        cout << "Taken out value is " << queue.dequeue() << endl;

    if (queue.isEmpty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    cout << "----- End of QueueList testing" << endl << endl;
}
