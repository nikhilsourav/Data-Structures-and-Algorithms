## Definition:

- Store similar data type in contiguous memory location.

## Advantages:

- ### Element access:
  - We can access any array element at O(1) time
  - An element at index 'x' is: <b>address of first element + (size of data) \* x</b>
- ### Cache friendliness:
  - It's a type of memory which is closest to CUP. Speed of access <b>cache: < Ram < Harddisk</b>
  - Idealy we want every item that our programm is accessing to be there in the cache.
  - When processor access an item, they prefetch and store nearby elements in cache according to cache limit.
  - Caching doen't work with other data structures like linked list.
