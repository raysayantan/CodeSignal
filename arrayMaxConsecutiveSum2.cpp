/*
Given an array of integers, find the maximum possible sum you can get from one of its contiguous subarrays. The subarray from which this sum comes must contain at least 1 element.

Example

For inputArray = [-2, 2, 5, -11, 6], the output should be
arrayMaxConsecutiveSum2(inputArray) = 7.

The contiguous subarray that gives the maximum possible sum is [2, 5], with a sum of 7.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer inputArray

An array of integers.

Guaranteed constraints:
3 ≤ inputArray.length ≤ 105,
-1000 ≤ inputArray[i] ≤ 1000.

[output] integer

The maximum possible sum of a subarray within inputArray.
*/
int arrayMaxConsecutiveSum2(std::vector<int> inputArray) {
    int len = inputArray.size();
    int maxSum = INT_MIN;
    int currSum = 0;
    int isAllNegative = true;
    for(int i = 0; i < len; i++){
        if(inputArray[i] >= 0){
            isAllNegative = false;
            break;
        }
        if(inputArray[i] > maxSum){
            maxSum = inputArray[i];
        }
    }

    if(isAllNegative == false){
        maxSum = inputArray[0];
        if(maxSum > 0) currSum = maxSum;
        else currSum = 0;
        for(int i = 1; i < len; i++){
            currSum += inputArray[i];

            if(currSum < 0){
                currSum = 0;
            }

            if(currSum > maxSum){
                maxSum = currSum;
            }
        }
    }

    return maxSum;
}
