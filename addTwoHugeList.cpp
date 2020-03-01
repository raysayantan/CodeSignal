/*
You're given 2 huge integers represented by linked lists. Each linked list element is a number from 0 to 9999 that represents a number with exactly 4 digits. The represented number might have leading zeros. Your task is to add up these huge integers and return the result in the same format.

Example

For a = [9876, 5432, 1999] and b = [1, 8001], the output should be
addTwoHugeNumbers(a, b) = [9876, 5434, 0].

Explanation: 987654321999 + 18001 = 987654340000.

For a = [123, 4, 5] and b = [100, 100, 100], the output should be
addTwoHugeNumbers(a, b) = [223, 104, 105].

Explanation: 12300040005 + 10001000100 = 22301040105.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] linkedlist.integer a

The first number, without its leading zeros.

Guaranteed constraints:
0 ≤ a size ≤ 104,
0 ≤ element value ≤ 9999.

[input] linkedlist.integer b

The second number, without its leading zeros.

Guaranteed constraints:
0 ≤ b size ≤ 104,
0 ≤ element value ≤ 9999.

[output] linkedlist.integer

The result of adding a and b together, returned without leading zeros in the same format.
*/
// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int>* reverseList(ListNode<int> *a){
    if(a == NULL) return NULL;
    if(a->next == NULL) return a;
    ListNode<int> *p = NULL, *c = a, *n = a->next;
    while(c){
        c->next = p;
        p = c;
        c = n;
        if(n)
            n = n->next;
    }

    return p;
}

ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
    if(a == NULL && b == NULL) return NULL;
    if(a == NULL) return b;
    if(b == NULL) return a;

    ListNode<int> *revA = reverseList(a);
    ListNode<int> *revB = reverseList(b);
    ListNode<int> *p = revA;
    ListNode<int> * q = revB;
    ListNode<int> *res = NULL;
    ListNode<int> * r = NULL;

    int carry = 0;
    while(p && q){
        int temp = p->value + q->value + carry;
        carry = temp/10000;
        ListNode<int> *t = new ListNode<int>();
        t->value = temp%10000;
        t->next = NULL;
        if(res == NULL) {
            res = t;
            r = res;
        } else {
            r->next = t;
            r = r->next;
        }
         
        p = p->next;
        q = q->next;
    }

    while(p){
        int temp = carry + p->value;
        carry = temp /10000;
        ListNode<int> *t = new ListNode<int>();
        t->value = temp%10000;
        t->next = NULL;
        r->next = t;
        r = r->next;
        p = p->next;
    }

    while(q){
        int temp = carry + q->value;
        carry = temp /10000;
        ListNode<int> *t = new ListNode<int>();
        t->value = temp%10000;
        t->next = NULL;
        r->next = t;
        r = r->next;
        q = q->next;
    }

    if(carry){
        ListNode<int> *t = new ListNode<int>();
        t->value = carry;
        t->next = NULL;
        r->next = t;
        r = r->next;
    }

    return reverseList(res);
}
