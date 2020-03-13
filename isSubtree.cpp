/*
Given two binary trees t1 and t2, determine whether the second tree is a subtree of the first tree. A subtree for vertex v in a binary
tree t is a tree consisting of v and all its descendants in t. Determine whether or not there is a vertex v (possibly none) in tree 
t1 such that a subtree for vertex v (possibly empty) in t1 equals t2.
This is what these trees look like:

      t1:             t2:
       5              10
      / \            /  \
    10   7          4    6
   /  \            / \    \
  4    6          1   2   -1
 / \    \
1   2   -1
As you can see, t2 is a subtree of t1 (the vertex in t1 with value 10).
the output should be isSubtree(t1, t2) = true.
This is what these trees look like:

        t1:            t2:
         5             10
       /   \          /  \
     10     7        4    6
   /    \           / \    \
  4     6          1   2   -1
 / \   / 
1   2 -1
As you can see, there is no vertex v such that the subtree of t1 for vertex v equals t2.
the output should be isSubtree(t1, t2) = false.
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
bool isCompareTree(Tree<int> *t1, Tree<int> *t2){
    if(t1 == NULL && t2 == NULL) return true;
    if(t1 == NULL) return false;
    if(t2 == NULL) return false;
    if(t1->value == t2->value){
        return isCompareTree(t1->left, t2->left) &&
               isCompareTree(t1->right, t2->right);
    }
    return false;
}
bool isSubtree(Tree<int> * t1, Tree<int> * t2) {
    if(t1 != NULL && t2 != NULL){
        if(t1->value == t2->value){
            return isCompareTree(t1, t2);
        } else {
            bool isLeft = isSubtree(t1->left, t2);
            bool isRight = isSubtree(t1->right, t2);

            if(isLeft) return isLeft;
            else return isRight;
        }
    } else if(t1 == NULL && t2 == NULL) return true;
    if(t1 == NULL && t2 != NULL) return false;
    return true;
}
