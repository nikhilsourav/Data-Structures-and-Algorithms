#include <bits/stdc++.h>
using namespace std;

// struct for queue node
struct QNode
{
    int data;
    QNode *next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};

// struct for queue
struct Queue
{
    // vars
    QNode *front, *rear;

    // constructor
    Queue()
    {
        front = rear = NULL;
    }

    // insert
    void enQueue(int x)
    {

        QNode *temp = new QNode(x);

        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    // delete
    void deQueue()
    {

        if (front == NULL)
            return;

        QNode *temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete (temp);
    }
};

// Driver code
int main()
{
    // Driver code
    Queue q;

    // insert
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.deQueue();

    // Peek front and rear items
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data;
}
