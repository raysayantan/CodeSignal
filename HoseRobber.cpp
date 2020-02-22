/*
You are planning to rob houses on a specific street, and you know that every house on the street has a certain amount of money hidden. The only thing stopping you from robbing all of them in one night is that adjacent houses on the street have a connected security system. The system will automatically trigger an alarm if two adjacent houses are broken into on the same night.

Given a list of non-negative integers nums representing the amount of money hidden in each house, determine the maximum amount of money you can rob in one night without triggering an alarm.

Example

For nums = [1, 1, 1], the output should be
houseRobber(nums) = 2.

The optimal way to get the most money in one night is to rob the first and the third houses for a total of 2.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer nums

An array representing the amount of money that each house on the street has.

Guaranteed constraints:
0 ≤ nums.length ≤ 100,
0 ≤ nums[i] ≤ 500.

[output] integer
*/
int MaxInt(int a, int b){
    return (a > b) ? a : b;
}

int houseRobber(std::vector<int> nums) {
    int len = nums.size();
    int maxVal = nums[0];
    int included = maxVal;
    int excluded = 0;

    if(len == 0) return 0;
    if(len == 1) return nums[0];
    if(len == 2) return MaxInt(nums[0], nums[1]);

    for(int i = 1; i < len; i++){
        maxVal = MaxInt(maxVal, MaxInt(excluded + nums[i], nums[i]));
        int t = included;
        included = maxVal;
        excluded = t;
    }

    return maxVal;
}
