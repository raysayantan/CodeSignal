/*
You need to climb a staircase that has n steps, and you decide to get some extra exercise by jumping up the steps. You can cover at most k steps in a single jump. Return all the possible sequences of jumps that you could take to climb the staircase, sorted.

Example

For n = 4 and k = 2, the output should be

climbingStaircase(n, k) =
[[1, 1, 1, 1],
 [1, 1, 2],
 [1, 2, 1],
 [2, 1, 1],
 [2, 2]]
There are 4 steps in the staircase, and you can jump up 2 or fewer steps at a time. There are 5 potential sequences in which you jump up the stairs either 2 or 1 at a time.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] integer n

Guaranteed constraints:
0 ≤ n ≤ 10.

[input] integer k

Guaranteed constraints:
0 ≤ k ≤ n.

[output] array.array.integer

An array containing all of the possible sequences in which you could climb n steps by taking them k or fewer at a time.
*/
void climbStairUtility(vector<vector<int>> &v, vector<int> t, int n, int k){
    if(n == 0) {
        v.push_back(t);
        return;
    }
    if(n == 1){
        t.push_back(n);
        v.push_back(t);
        return;
    }

    for(int i = 1; i <= k; i++){
        if(i < n){
            t.push_back(i);
            climbStairUtility(v, t, n - i, k);
            t.pop_back();
        } else if(i == n){
            t.push_back(i);
            v.push_back(t);
            return;
        }
    }
}
std::vector<std::vector<int>> climbingStaircase(int n, int k) {
    vector<vector<int>> pathArray;
    vector<int> t;
    int idx = 0;
    climbStairUtility(pathArray, t, n, k);
    return pathArray;
}
