- ## Left shift (<<):
  Assuming that the leading <strong> y </strong> bits of a 32 bit number are zero eg: 0...0010,
  The result of (x << y) is: <strong> x\*2<sup>y</sup> </strong>.

<br></br>

- ## Right shift (>>):

  The result of (x >> y) is equivalent to: <strong> [x/2 <sup>y</sup>] </strong>, where [ ] is floor function.

<br></br>

- ## Negation (~)

  The negation of a number inverts all 0 to 1 or vice versa.

<br></br>

- ## XOR (^)

  Important properties of XOR:

  ```
  x^x = 0
  x^0 = x
  x^y = y^x
  x^(y^z) = (x^y)^z
  ```

<br></br>

- ## NOTE:
  <strong>
  It is not recommended to use left shift, right shift or negation on negative numbers.
  </strong>
