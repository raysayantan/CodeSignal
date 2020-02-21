/*
You are climbing a staircase that has n steps. You can take the steps either 1 or 2 at a time. Calculate how many distinct ways you can climb to the top of the staircase.

Example

For n = 1, the output should be
climbingStairs(n) = 1;

For n = 2, the output should be
climbingStairs(n) = 2.

You can either climb 2 steps at once or climb 1 step two times.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] integer n

Guaranteed constraints:
1 ≤ n ≤ 50.

[output] integer

It's guaranteed that the answer will fit in a 32-bit integer.
*/
int ClimbStairUtily(map<int, int> &counter, int n){
    
    if(n == 1) {
        if(counter.find(1) == counter.end()) counter[1] = 1;
        return 1;
    }

    if(n == 2) {
        if(counter.find(2) == counter.end()) counter[2] = 2;        
        return 2;
    }

    int temp1;
    int temp2;
    if(counter.find(n-1) != counter.end()) {
        temp1 = counter[n-1];
    } else {
        temp1 = ClimbStairUtily(counter, n-1);
    }

    if(counter.find(n-2) != counter.end()){
        temp2 = counter[n-2];
    } else {
        temp2 = ClimbStairUtily(counter, n-2);
    }

    
    counter[n] = temp1 + temp2;
    return temp1 + temp2;
}

int climbingStairs(int n) {
    map<int, int> counter;

    return ClimbStairUtily(counter, n);
}
