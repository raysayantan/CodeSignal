/*
Given a sequence of numbers in an array, find the length of its longest increasing subsequence (LIS).
The longest increasing subsequence is a subsequence of a given sequence in which the subsequence's elements are in strictly increasing order, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous or unique.

Example

For sequence = [1, 231, 2, 4, 89, 32, 12, 234, 33, 90, 34, 100], the output should be
longestIncreasingSubsequence(sequence) = 7.

The LIS itself is [1, 2, 4, 32, 33, 34, 100].

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer sequence

An array describing a sequence.

Guaranteed constraints:
1 ≤ sequence.length ≤ 1000,
0 ≤ sequence[i] ≤ 106.

[output] integer

The length of the longest increasing subsequence of a given sequence.
*/
int longestIncreasingSubsequence(std::vector<int> sequence) {
    int len = sequence.size();
    if(len == 0) return 0;
    int maxChain = 1;
    vector<int> countArray(len);
    countArray[0] = 1;
    for(int i = 1; i < len; i++){
        int temp = sequence[i];
        int k = i-1;
        int currMax = 0;
        while(k >= 0){
            if(sequence[k] < temp){
                if(currMax < countArray[k]) currMax = countArray[k];
                if(currMax == maxChain) break;
            }
            k--;
        }
        countArray[i] = currMax + 1;
        if(maxChain < countArray[i]) maxChain = countArray[i];
    }

    return maxChain;
}
