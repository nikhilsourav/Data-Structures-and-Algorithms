## Definition:

- Queues are a type of container adaptors which operate in a first in first out <b>(FIFO)</b> type of arrangement. Elements are inserted at the back (end) and are deleted from the front.

## Operations:

- enQueue: Insert element at the end
- deQueue: Remove element from front
- getFront: Peek front item without deleting
- getRear: Peek rear item without deleting
- size: Size of queue
- isEmpty: Check if queue is empty

## Applications:

- Single resource and multiple consumers
- Synchronization between slow and fast devices
- In operating system (semaphores, FCFS scheduling, spooling, buffer for devices like keyboard)
- In computer networks (routers/switches and mail queues)
- Variations: Deque, Priority Queue, Doubly Ended Priority Queue

## Implementations:

- Using array/vector
- Using linked list
