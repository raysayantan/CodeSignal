/*
Note: Avoid using built-in std::nth_element (or analogous built-in functions in languages other than C++) when solving this challenge. Implement them yourself, since this is what you would be asked to do during a real interview.

Find the kth largest element in an unsorted array. This will be the kth largest element in sorted order, not the kth distinct element.

Example

For nums = [7, 6, 5, 4, 3, 2, 1] and k = 2, the output should be
kthLargestElement(nums, k) = 6;
For nums = [99, 99] and k = 1, the output should be
kthLargestElement(nums, k) = 99.
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer nums

Guaranteed constraints:
1 ≤ nums.length ≤ 105,
-105 ≤ nums[i] ≤ 105.

[input] integer k

Guaranteed constraints:
1 ≤ k ≤ nums.length.

[output] integer
*/
int kthLargestElement(std::vector<int> nums, int k) {
    multiset<int> sorted;

    int len = nums.size();

    for(int i = 0; i < len; i++){
        sorted.insert(nums[i]);
    }

    int target = len - k;
    int counter = 0;
    int result;

    for(auto it = sorted.begin(); it != sorted.end(); it++){
        if(counter == target){
            result = *it;
            break;
        }
        
        counter++;
    }

    return result;
}
