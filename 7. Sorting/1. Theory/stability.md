## General idea of stability

- If two items have same value then they should appear in the same order as they appeard in original data.<br>

- Given name of student and their marks:<br>
  arr[] = [("Anil", 50), ("Ayan", 80), ("Piyush, 50), ("Ramesh", 80)]<br>

- <b>stable algorithm:</b> (maintain alphabetical order and increasing order of marks)<br>
  arr[] = [("Anil", 50), ("Piyush, 50), ("Ayan", 80), ("Ramesh", 80)]<br>

- <b>unstable algorithm:</b> (only care about increasing order of marks)<br>
  May produce any combination. But ensures increasing order of marks

## Need of stability

- Stability is important when we have objects of multiple forms.<br>

- When we have only int array for eg, we don't need stability.

| Stable sorting algorithm | Unstable sorting Algorithm |
| ------------------------ | -------------------------- |
| Bubble sort              | Selection sort             |
| Merge sort               | Quick sort                 |
| Insertion sort           | Heap sort                  |
