/*
Given a binary tree t and an integer s, determine whether there is a root to leaf path in 
t such that the sum of vertex values equals s.
s = 7,
the output should be hasPathWithGivenSum(t, s) = true.

This is what this tree looks like:

      4
     / \
    1   3
   /   / \
  -2  1   2
    \    / \
     3  -2 -3
Path 4 -> 3 -> 2 -> -2 gives us 7, the required sum.

s = 7,
the output should be hasPathWithGivenSum(t, s) = false.

This is what this tree looks like:

      4
     / \
    1   3
   /   / \
  -2  1   2
    \    / \
     3  -4 -3
There is no path from root to leaf with the given sum 7.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] tree.integer t

A binary tree of integers.

Guaranteed constraints:
0 ≤ tree size ≤ 5 · 104,
-1000 ≤ node value ≤ 1000.

[input] integer s

An integer.

Guaranteed constraints:
-4000 ≤ s ≤ 4000.

[output] boolean

Return true if there is a path from root to leaf in t such that the sum of node values in it is equal to s, otherwise return false.
*/
bool hasPathOfSum(Tree<int> *t, int s){
    if(t == NULL) return false;
    if((t->left == NULL && t->right == NULL) && s - t->value != 0) return false;
    if((t->left == NULL && t->right == NULL) && s - t->value == 0) return true;

    bool isLeft = false;
    bool isRight = false;
    if(t->left)
        isLeft = hasPathOfSum(t->left, s - t->value);
    if(t->right)
        isRight = hasPathOfSum(t->right, s - t->value);

    return (isLeft | isRight);
}

bool hasPathWithGivenSum(Tree<int> * t, int s) {
    return hasPathOfSum(t,s);
}
