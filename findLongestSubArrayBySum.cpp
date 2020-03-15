/*
You have an unsorted array arr of non-negative integers and a number s. Find a longest contiguous subarray in arr that has a 
sum equal to s. Return two integers that represent its inclusive bounds. If there are several possible answers, return the one 
with the smallest left bound. If there are no answers, return [-1].

Your answer should be 1-based, meaning that the first position of the array is 1 instead of 0.

Example

For s = 12 and arr = [1, 2, 3, 7, 5], the output should be
findLongestSubarrayBySum(s, arr) = [2, 4].

The sum of elements from the 2nd position to the 4th position (1-based) is equal to 12: 2 + 3 + 7.

For s = 15 and arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], the output should be
findLongestSubarrayBySum(s, arr) = [1, 5].

The sum of elements from the 1st position to the 5th position (1-based) is equal to 15: 1 + 2 + 3 + 4 + 5.

For s = 15 and arr = [1, 2, 3, 4, 5, 0, 0, 0, 6, 7, 8, 9, 10], the output should be
findLongestSubarrayBySum(s, arr) = [1, 8].

The sum of elements from the 1st position to the 8th position (1-based) is equal to 15: 1 + 2 + 3 + 4 + 5 + 0 + 0 + 0.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] integer s

The sum of the subarray that you are searching for.

Guaranteed constraints:
0 ≤ s ≤ 109.

[input] array.integer arr

The given array.

Guaranteed constraints:
1 ≤ arr.length ≤ 105,
0 ≤ arr[i] ≤ 104.

[output] array.integer

An array that contains two elements that represent the left and right bounds of the subarray, respectively (1-based). 
If there is no such subarray, return [-1].
*/
std::vector<int> findLongestSubarrayBySum(int s, std::vector<int> arr) {
    vector<int> res(2);
    res[0] = -1;
    int start = 0;
    int end = 1;
    int currSum = 0;
    int len = arr.size();

    if(len == 0) return vector{-1};
    if(len == 1 && s == arr[0]){
        return vector{1,1};
    }
    currSum = arr[0];
    while(start <= end && end < len){
        if(currSum < s){
            currSum += arr[end];
            if(currSum < s)
                end++;
        } else if(currSum > s){
            currSum -= arr[start];
            start++;
            if(currSum < s) end++;
        } else if(currSum == s){
            if(res[0] == -1){
                res[0] = start + 1;
                res[1] = end + 1;
            } else {
                int range = res[1] - res[0];
                if(range < (end - start)){
                    res[0] = start + 1;
                    res[1] = end + 1;
                }
            }
            end++;
            if(end < len) currSum += arr[end];
        }
    }

    if(res[0] == -1) return vector{-1};
    else return res;
}
