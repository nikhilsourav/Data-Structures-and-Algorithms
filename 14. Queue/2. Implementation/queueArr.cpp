#include <bits/stdc++.h>
using namespace std;

// Queue class
class Queue
{
public:
    int front, rear, size;
    unsigned capacity;
    int *array;
};

// create queue
Queue *createQueue(unsigned capacity)
{
    Queue *queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity - 1;
    queue->array = new int[(
        queue->capacity * sizeof(int))];
    return queue;
}

// check if queue is full
int isFull(Queue *queue)
{
    return (queue->size == queue->capacity);
}

// check if queue is empty
int isEmpty(Queue *queue)
{
    return (queue->size == 0);
}

// insert item in queue
void enqueue(Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    cout << item << " enqueued to queue\n";
}

// remove item from queue
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// peek first element in queue
int front(Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// peek last element in queue
int rear(Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

// Driver code
int main()
{
    // create queue
    Queue *queue = createQueue(1000);

    // insert items
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // delete item from queue
    cout << dequeue(queue) << " dequeued from queue\n";

    // check front and rear item
    cout << "Front item is " << front(queue) << endl;
    cout << "Rear item is " << rear(queue) << endl;
}
