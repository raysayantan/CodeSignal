/*
You are given an array of integers in which every element appears twice, except for one. Find the element that only appears one time. Your solution should have a linear runtime complexity (O(n)). Try to implement it without using extra memory.

Example

For nums = [2, 2, 1], the output should be
singleNumber(nums) = 1.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer nums

Guaranteed constraints:
1 ≤ nums.length < 104,
-109 ≤ nums[i] ≤ 109.

[output] integer
*/
int singleNumber(std::vector<int> nums) {
  int res = 0;
  for (int num : nums) {
    res ^= num;
  }
  return res;
}
