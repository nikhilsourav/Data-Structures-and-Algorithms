/*
    Queue implementation
*/

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

// Create queue
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

// Check if queue is full
int isFull(Queue *queue)
{
    return (queue->size == queue->capacity);
}

// Check if queue is empty
int isEmpty(Queue *queue)
{
    return (queue->size == 0);
}

// Insert item in queue
void enqueue(Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    cout << item << " enqueued to queue\n";
}

// Remove item from queue
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Peek first element in queue
int front(Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Peek last element in queue
int rear(Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

// Driver code
int main()
{
    // Create queue
    Queue *queue = createQueue(1000);

    // Insert items
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Delete item from queue
    cout << dequeue(queue) << " dequeued from queue\n";

    // Check front and rear item
    cout << "Front item is " << front(queue) << endl;
    cout << "Rear item is " << rear(queue) << endl;
}
