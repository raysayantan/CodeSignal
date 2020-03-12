/*
Note: Your solution should have only one BST traversal and O(1) extra space complexity, since this is what you will be asked to accomplish in an interview.
Given a binary search tree t, find the kth smallest element in it.

Note that kth smallest element means kth element in increasing order. See examples for better understanding.
k = 4, the output should be
kthSmallestInBST(t, k) = 5.

Here is what t looks like:

   3
 /   \
1     5
     / \
    4   6
The values of t are [1, 3, 4, 5, 6], and the 4th smallest is 5.
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
int findKthSmallestUtility(Tree<int> *t, int k, int &cnt){
    int leftRet = -100001, rightRet = -100001;
    
    if(t != NULL){
        if(cnt < k && t->left != NULL){
           leftRet = findKthSmallestUtility(t->left, k, cnt);
        }
        cnt++;
        if(cnt == k) return t->value;
        if(cnt < k && t->right != NULL){
            rightRet = findKthSmallestUtility(t->right, k, cnt);
        }
    }

    if(leftRet != -100001) return leftRet;
    else return rightRet;
}
int kthSmallestInBST(Tree<int> * t, int k) {
    int cnt = 0;
    return findKthSmallestUtility(t, k, cnt);
}
