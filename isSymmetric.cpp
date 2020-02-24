/*
Given a binary tree t, determine whether it is symmetric around its center, i.e. each side mirrors the other.
Here's what the tree in this example looks like:

    1
   / \
  2   2
 / \ / \
3  4 4  3
As you can see, it is symmetric.

Here's what the tree in this example looks like:

    1
   / \
  2   2
   \   \
   3    3
As you can see, it is not symmetric.
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] tree.integer t

A binary tree of integers.

Guaranteed constraints:
0 ≤ tree size < 5 · 104,
-1000 ≤ node value ≤ 1000.

[output] boolean

Return true if t is symmetric and false otherwise.
*/
//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool isSymmetricUtil(Tree<int> *left, Tree<int> *right){
    if(left == NULL && right == NULL) return true;
    if(left == NULL && right != NULL) return false;
    if(left != NULL && right == NULL) return false;
    if(left->value == right->value){
        if(left->left->value == right->left->value && left->right->value == right->right->value){
            return (isSymmetricUtil(left->left, right->right) 
                    && isSymmetricUtil(left->right, right->left));
        }
    } else {
        return false;
    }
}
bool isTreeSymmetric(Tree<int> * t) {
    if(t == NULL) return true;
    return isSymmetricUtil(t->left, t->right);
}
