/*
Given a sorted integer array that does not contain any duplicates, return a summary of the number ranges it contains.

Example

For nums = [-1, 0, 1, 2, 6, 7, 9], the output should be
composeRanges(nums) = ["-1->2", "6->7", "9"].

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer nums

A sorted array of unique integers.

Guaranteed constraints:
0 ≤ nums.length ≤ 15,
-(231 - 1) ≤ nums[i] ≤ 231 - 1.

[output] array.string
*/
void printRange(vector<string> &output, int start, int end)
{
    if(start == end){
        output.push_back(to_string(start));
    } else {
        output.push_back(to_string(start)+"->"+to_string(end));
    }
}
std::vector<std::string> composeRanges(std::vector<int> nums) {
    int len = nums.size();
    vector<string> output;
    if(len == 0) return output;

    int start = nums[0];
    int end = start;

    for(int i = 1; i < len; i++){
        if(nums[i] != nums[i-1] + 1){
            end = nums[i-1];
            printRange(output, start, end);
            start = nums[i];
            end = start;
        } else {
            end = nums[i];
        }
    }

    printRange(output, start, end);

    return output;
}
