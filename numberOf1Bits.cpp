/*
Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
Note: Avoid using built-in functions that convert integers to their binary representations. Write the solution that uses O(k) operations per test, where k is the number of bits set to 1.

Write a function that takes an unsigned (positive) integer and returns the number of 1 bits its binary representation contains. This value is also known as the integer's Hamming weight.

Example

For n = 13, the output should be
numberOf1Bits(n) = 3.

13 is represented in binary as 1101, so the function should return 3.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] integer n

Guaranteed constraints:
0 ≤ n ≤ 231 - 1.

[output] integer
*/
int numberOf1Bits(int n) {
  int res = 0;
  while (n != 0) {
    n = n&(n-1);
    res++;
  }
  return res;
}
