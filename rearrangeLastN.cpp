/*
Note: Try to solve this task in O(list size) time using O(1) additional space, since this is what you'll be asked during an interview.

Given a singly linked list of integers l and a non-negative integer n, move the last n list nodes to the beginning of the linked list.

Example

For l = [1, 2, 3, 4, 5] and n = 3, the output should be
rearrangeLastN(l, n) = [3, 4, 5, 1, 2];
For l = [1, 2, 3, 4, 5, 6, 7] and n = 1, the output should be
rearrangeLastN(l, n) = [7, 1, 2, 3, 4, 5, 6].
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] linkedlist.integer l

A singly linked list of integers.

Guaranteed constraints:
0 ≤ list size ≤ 105,
-1000 ≤ element value ≤ 1000.

[input] integer n

A non-negative integer.

Guaranteed constraints:
0 ≤ n ≤ list size.

[output] linkedlist.integer

Return l with the n last elements moved to the beginning.
*/
// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {
    ListNode<int> *p = l;
    ListNode<int> *end = NULL;
    ListNode<int> *brPoint = NULL;
    int counter = 0;

    if(l == NULL) return l;
    if(n == 0) return l;

    while(p != NULL){
        if(p->next == NULL) end = p;
        p = p->next;
        counter++;
    }

    if(n == counter) return l;

    int toMove = counter - n;
    counter = 1;
    p = l;
    
    while(counter < toMove){
        p = p->next;
        counter++;
    }

    if(p->next) brPoint = p->next;
    p->next = NULL;
    end->next = l;
    return brPoint;
}
