/*
Note: Your solution should have O(inorder.length) time complexity, since this is what you will be asked to accomplish in an interview.

Let's define inorder and preorder traversals of a binary tree as follows:

Inorder traversal first visits the left subtree, then the root, then its right subtree;
Preorder traversal first visits the root, then its left subtree, then its right subtree.
For example, if tree looks like this:

    1
   / \
  2   3
 /   / \
4   5   6
then the traversals will be as follows:

Inorder traversal: [4, 2, 1, 5, 3, 6]
Preorder traversal: [1, 2, 4, 3, 5, 6]
Given the inorder and preorder traversals of a binary tree t, but not t itself, restore t and return it.

Example

For inorder = [4, 2, 1, 5, 3, 6] and preorder = [1, 2, 4, 3, 5, 6], the output should be
restoreBinaryTree(inorder, preorder) = {
    "value": 1,
    "left": {
        "value": 2,
        "left": {
            "value": 4,
            "left": null,
            "right": null
        },
        "right": null
    },
    "right": {
        "value": 3,
        "left": {
            "value": 5,
            "left": null,
            "right": null
        },
        "right": {
            "value": 6,
            "left": null,
            "right": null
        }
    }
}
For inorder = [2, 5] and preorder = [5, 2], the output should be
restoreBinaryTree(inorder, preorder) = {
    "value": 5,
    "left": {
        "value": 2,
        "left": null,
        "right": null
    },
    "right": null
}
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer inorder

An inorder traversal of the tree. It is guaranteed that all numbers in the tree are pairwise distinct.

Guaranteed constraints:
1 ≤ inorder.length ≤ 2 · 103,
-105 ≤ inorder[i] ≤ 105.

[input] array.integer preorder

A preorder traversal of the tree.

Guaranteed constraints:
preorder.length = inorder.length,
-105 ≤ preorder[i] ≤ 105.

[output] tree.integer

The restored binary tree.
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
int findIndex(int val, vector<int> in, int start, int end){
    for(int i = start; i <= end; i++){
        if(in[i] == val) return i;
    }

    return -1;
}
Tree<int> *restoreBinaryTreeUtility(vector<int> in, vector<int> pre, int start, int end, int &idx){
    if(start > end) return NULL;
    if(start == end){
        Tree<int> *t = new Tree<int>();
        t->value = in[start];
        t->left = NULL;
        t->right = NULL;
        idx++;
        return t;
    }

    int temp = pre[idx];
    int inIdx = findIndex(pre[idx++], in, start, end);
    Tree<int> *t = new Tree<int>();
    t->value = temp;
    t->left = restoreBinaryTreeUtility(in, pre, start, inIdx - 1, idx);
    t->right = restoreBinaryTreeUtility(in, pre, inIdx + 1, end, idx);
    return t;
}
Tree<int> * restoreBinaryTree(std::vector<int> inorder, std::vector<int> preorder) {
    int len = inorder.size();
    int start = 0;
    int end = len - 1;
    int idx = 0;
    return restoreBinaryTreeUtility(inorder, preorder, start, end, idx);
}
