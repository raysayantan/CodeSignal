/*
You have an array of integers nums and an array queries, where queries[i] is a pair of indices (0-based). Find the sum of the elements in nums from the indices at queries[i][0] to queries[i][1] (inclusive) for each query, then add all of the sums for all the queries together. Return that number modulo 109 + 7.

Example

For nums = [3, 0, -2, 6, -3, 2] and queries = [[0, 2], [2, 5], [0, 5]], the output should be
sumInRange(nums, queries) = 10.

The array of results for queries is [1, 3, 6], so the answer is 1 + 3 + 6 = 10.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer nums

An array of integers.

Guaranteed constraints:
1 ≤ nums.length ≤ 105,
-1000 ≤ nums[i] ≤ 1000.

[input] array.array.integer queries

An array containing sets of integers that represent the indices to query in the nums array.

Guaranteed constraints:
1 ≤ queries.length ≤ 3 · 105,
queries[i].length = 2,
0 ≤ queries[i][j] ≤ nums.length - 1,
queries[i][0] ≤ queries[i][1].

[output] integer

An integer that is the sum of all of the sums gotten from querying nums, taken modulo 10^9 + 7.
*/
int sumInRange(std::vector<int> nums, std::vector<std::vector<int>> queries) {
    map<int, long long> leftSum;
    map<int, long long> rightSum;
    int len = nums.size();

    leftSum[0] = 0;
    long long currSum = 0;
    long long totalSum = 0;
    for(int i = 1; i < len; i++){
        currSum += nums[i-1];
        leftSum[i]= currSum; 
    }   

    totalSum = currSum + nums[len-1];
    currSum = 0;
    rightSum[len - 1] = 0;
    for(int i = len - 2; i >= 0; i--){
        currSum += nums[i+1];
        rightSum[i] = currSum;
    }

    int numOfQueries = queries.size();
    long long left = 0, right = 0, total = 0;
    for(int i = 0; i < numOfQueries; i++){
        int start = queries[i][0];
        int end = queries[i][1];

        left = leftSum[start];
        right = rightSum[end];
        long long temp = totalSum - left - right;
        total += temp;
    }

    return (total +  1000000007)%1000000007;
}
