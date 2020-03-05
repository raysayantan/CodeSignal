/*
Note: Your solution should have O(n) time complexity, where n is the number of elements in l, and O(1) additional space complexity, since this is what you would be asked to accomplish in an interview.

Given a linked list l, reverse its nodes k at a time and return the modified list. k is a positive integer that is less than or equal to the length of l. If the number of nodes in the linked list is not a multiple of k, then the nodes that are left out at the end should remain as-is.

You may not alter the values in the nodes - only the nodes themselves can be changed.

Example

For l = [1, 2, 3, 4, 5] and k = 2, the output should be
reverseNodesInKGroups(l, k) = [2, 1, 4, 3, 5];
For l = [1, 2, 3, 4, 5] and k = 1, the output should be
reverseNodesInKGroups(l, k) = [1, 2, 3, 4, 5];
For l = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11] and k = 3, the output should be
reverseNodesInKGroups(l, k) = [3, 2, 1, 6, 5, 4, 9, 8, 7, 10, 11].
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] linkedlist.integer l

A singly linked list of integers.

Guaranteed constraints:
1 ≤ list size ≤ 104,
-109 ≤ element value ≤ 109.

[input] integer k

The size of the groups of nodes that need to be reversed.

Guaranteed constraints:
1 ≤ k ≤ l size.

[output] linkedlist.integer

The initial list, with reversed groups of k elements.
*/
// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
    ListNode<int> *start = NULL;
    ListNode<int> *prev = NULL;
    ListNode<int> *c = NULL, *p = l, *old = NULL;
    ListNode<int> *n = NULL;
    ListNode<int> *s = NULL, *ps = NULL;
    ListNode<int> *e = NULL, *pe = NULL;
    int cnt = 0;
    
    if(l == NULL) return NULL;
    if(k == 1) return l;

    while(true){
        e = p;
        while(cnt < k && p != NULL){
            old = p;
            p = p->next;
            cnt++;
        }

        if(k == cnt){
            prev = NULL;
            c = e;
            while(c != p){
                if(c)
                    n = c->next;
                c->next = prev;
                prev = c;
                c = n;
            }
            s = prev;
            if(start == NULL){
                start = s;
            } else{
                pe->next = s;
            }
            pe = e;
            ps = s;
            cnt = 0;
        } else {
            pe->next = e;
            break;
        }
    }

    return start;
}
