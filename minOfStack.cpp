/*
Note: Write a solution with O(operations.length) complexity, since this is what you would be asked to do during a real interview.

Implement a modified stack that, in addition to using push and pop operations, allows you to find the current minimum element in the stack by using a min operation.

Example

For operations = ["push 10", "min", "push 5", "min", "push 8", "min", "pop", "min", "pop", "min"], the output should be
minimumOnStack(operations) = [10, 5, 5, 5, 10].

The operations array contains 5 instances of the min operation. The results array contains 5 numbers, each representing the minimum element in the stack at the moment when min was called.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.string operations

An array of operations consistently applied to the stack. For each valid i, operations[i] is one of the following operations:

push x: add the number x to the stack;
pop: remove an element from the top of the stack;
min: find the minimum element from the current stack elements.
It is guaranteed that pop and min are not applied to an empty stack. It is also guaranteed that all of the numbers in the stack are positive and not greater than 109.
Guaranteed constraints:
1 ≤ operations.length ≤ 104.

[output] array.integer

For each min operation, return the minimum element from the current stack elements at the moment when the operation was called.
*/
struct _DATA {
    int val;
    int min;
};
class MyStack {
    private:
    _DATA data[10000];
    int top;
    public:
    MyStack() : top(-1){}
    void push(int ele){
        int temp = -1;
        if(top == 9999) return;
        if(top == -1){
            data[++top].min = ele;
            data[top].val = ele; 
        } else {
            temp = data[top].min;
            temp = (temp < ele) ? temp :  ele;
            data[++top].val = ele;
            data[top].min = temp;
        }
    }

    void pop(){
        if(empty()) return;
        top--;
    }

    int minVal(){
        if(empty()) return -1;
        return data[top].min;
    }

    bool empty(){
        return (top == -1) ? true : false;
    }
};
std::vector<int> minimumOnStack(std::vector<std::string> operations) {
    MyStack st;
    int numOfOp = operations.size();
    vector<int> res;

    for(int i = 0; i < numOfOp; i++){
        if(operations[i] == "pop"){
            st.pop();
        } else if(operations[i] == "min"){
            int temp = st.minVal();
            if(temp != -1) res.push_back(temp);
        } else {
            int value = stoi(operations[i].c_str() + string("push").length());
            st.push(value);
        }
    }

    return res;
}
