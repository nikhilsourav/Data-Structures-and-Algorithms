## Tree traversal can be classified into two categories:

**Depth First:**

- Visit one side, finish it completely then visit other side. Total 3! = 6 type of traversal is possible but we use these three:

  - **Inorder:** Left Root Right (root in between, direction L->R)
  - **Preorder:** Root Left Right (root at the beginning, direction L->R)
  - **Postorder:** Left Right Root (root at the end, direction L->R)

**Breadth First or Level Order:**

- Each node printed from left to right line by line.

  <br/>

**Example:**

```
      10
     /  \
    20  30

  Breadth First: 10 20 30
  Depth First:
    Inorder: 20 10 30
    Preorder: 10 20 30
    Postorder: 20 30 10


         10
        /  \
       20   30
      /  \    \
     40   50   60
    /  \
   70   80

  Breadth First: 10 20 30 40 50 60 70 80
  Depth First
    Inorder: 70 40 80 20 50 10 30 60
    Preorder: 10 20 40 70 80 50 30 60
    PostOrder: 70 80 40 50 20 60 30 10
```
