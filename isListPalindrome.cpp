/*
Note: Try to solve this task in O(n) time using O(1) additional space, where n is the number of elements in l, since this is what you'll be asked to do during an interview.

Given a singly linked list of integers, determine whether or not it's a palindrome.

Note: in examples below and tests preview linked lists are presented as arrays just for simplicity of visualization: in real data you will be given a head node l of the linked list

Example

For l = [0, 1, 0], the output should be
isListPalindrome(l) = true;

For l = [1, 2, 2, 3], the output should be
isListPalindrome(l) = false.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] linkedlist.integer l

A singly linked list of integers.

Guaranteed constraints:
0 ≤ list size ≤ 5 · 105,
-109 ≤ element value ≤ 109.

[output] boolean

Return true if l is a palindrome, otherwise return false.
*/
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
bool isPalindromeCore(ListNode<int> * l, ListNode<int> ** start){
    if(l == NULL) return true;
    if(l->next == NULL) {
        if(l->value == (*start)->value || *start == l) return true;
        else return false;
    }
    
    bool isPalindrome = isPalindromeCore(l->next, start);
    
    if(isPalindrome) {
        if((*start) != l || (*start)->next != l)
            (*start) = (*start)->next;
        if((*start) == l){
            return true;
        } else if((*start)->next == l){
            if((*start)->value == l->value) return true;
            else return false;

        } else if((*start)->value == l->value){
            return true;
        } else return false;
    } else {
        return false;
    }

    return true;
}
bool isListPalindrome(ListNode<int> * l) {
    ListNode<int> * start = l;
    return isPalindromeCore(l, &start);
}
