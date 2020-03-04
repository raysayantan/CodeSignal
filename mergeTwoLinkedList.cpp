/*
Note: Your solution should have O(l1.length + l2.length) time complexity, since this is what you will be asked to accomplish in an interview.

Given two singly linked lists sorted in non-decreasing order, your task is to merge them. In other words, return a singly linked list, also sorted in non-decreasing order, that contains the elements from both original lists.

Example

For l1 = [1, 2, 3] and l2 = [4, 5, 6], the output should be
mergeTwoLinkedLists(l1, l2) = [1, 2, 3, 4, 5, 6];
For l1 = [1, 1, 2, 4] and l2 = [0, 3, 5], the output should be
mergeTwoLinkedLists(l1, l2) = [0, 1, 1, 2, 3, 4, 5].
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] linkedlist.integer l1

A singly linked list of integers.

Guaranteed constraints:
0 ≤ list size ≤ 104,
-109 ≤ element value ≤ 109.

[input] linkedlist.integer l2

A singly linked list of integers.

Guaranteed constraints:
0 ≤ list size ≤ 104,
-109 ≤ element value ≤ 109.

[output] linkedlist.integer

A list that contains elements from both l1 and l2, sorted in non-decreasing order.
*/
// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {
    ListNode<int> *prev = NULL;
    ListNode<int> *p = NULL;
    ListNode<int> *q = NULL;
    ListNode<int> *start = NULL;

    if(l1 == NULL && l2== NULL) return NULL;
    if(l1 == NULL && l2) return l2;
    if(l2 == NULL && l1) return l1;

    if(l1->value < l2->value){
        p = l1;
        q = l2;
    } else {
        p = l2;
        q = l1;
    }

    if(start == NULL){
        start = p;
        prev = p;
        p = p->next;
    }

    while(p && q){
        if(p->value < q->value){
            prev->next = p;
            p = p->next;
        } else {
            prev->next = q;
            q = q->next;
        }

        prev = prev->next;
    }

    if(p){
        prev->next = p;
    } else if(q){
        prev->next = q;
    }

    return start;
}
