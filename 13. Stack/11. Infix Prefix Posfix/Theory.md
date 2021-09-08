<h1 align="center"> Precedence and Associativity: </h1>

## 1. Rules:

- These rules are used when we have two or more operators in an expression

- If there are two operators with different precedence:

  - then we evaluate highest precedence operator first
  - then lower precendence and then lowest precedence operator

  <br/>

- If there are two operators with same precedence:

  - we follow associativity rules
  - if associativity is left to right then we evaluate left first
  - if associativity ir right to left then right first

  <br/>

- **Note: All operator of same precedence have same associativity either left to right or right to left**

<br/>

## 2. Precedence table:

- Example of few operators:

- | Precedence | Operators | Associativity |
  | :--------: | :-------: | ------------- |
  |     1      |     !     | Right to left |
  |     2      |  \* / %   | Left to right |
  |     3      |    + -    | Left to right |

- '!' has highest precedence then '\*', '/', '%' then '+', '-'
- Precedence list of all operators [cppreference](https://doc.bccnsoft.com/docs/cppreference_en/operator_precedence.html)

<br/>

<h1 align = "center"> Introduction to infix, prefix and postfix: </h1>

## 1. Example:

<br/>

```
Infix:   (x + y)    // operator appear in between operands
Prefix:   (+xy)     // operator appear before operands
Postfix:  (xy+)     // operator appear after operands
```

<br/>

## 2. Advantages:

<br/>

- Do not require paranthesis, precedence rules and associativity rules.
- Can be evaluated by traversing given expression exactly once

<br/>

## 3. Conversion:

<br/>

```
// ================ Example 1 ================== //

Infix:    (x + y * z)

Prefix:   (x + (y * z))
          (x + (* y z))
          (+ x (* y z))
          + x * y z

Postfix:  (x + (y * z))
          (x + (y z *))
          (x (y z *) +)
          x y z * +


// ================ Example 2 ================== //

Infix:    (x + y) * z

Prefix:   (+ x y) * z
          (* (+ x y) z)
          * + x y z

Postfix:  (x y +) * z
          (x y +) z *
          x y + z *
```
