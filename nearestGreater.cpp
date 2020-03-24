/*
Given an array of integers a, return a new array b using the following guidelines:

For each index i in b, the value of bi is the index of the aj nearest to ai and is also greater than ai.
If there are two options for bi, put the leftmost one in bi.
If there are no options for bi, put -1 in bi.
Example

For a = [1, 4, 2, 1, 7, 6], the output should be
nearestGreater(a) = [1, 4, 1, 2, -1, 4].

for a[0], the nearest larger element is 4 at index a[1] -> b[0] contains the value 1.
for a[1], the nearest larger element is 7 at a[4] -> b[1] contains the value 4.
for a[2], the nearest larger element is 4 at a[1] (7 is also larger, but 4 has the minimal position) -> b[2] contains the value 1.
for a[3], the nearest larger element is 2 at a[2] (7 is also larger, but 2 has the minimal position) -> b[3] contains the value 2.
for a[4], there is no element larger than 7 -> b[4] contains the value -1.
for a[5], the nearest larger element is 7 at a[4] -> b[5] contains the value 4.
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer a

An unsorted array of integers.

Guaranteed constraints:
1 ≤ a.length ≤ 4 · 104,
1 ≤ a[i] ≤ 109.

[output] array.integer

An array b, where for each index i, bi is the index of the nearest number in a that is greater than ai.
*/
#include <ios>
std::vector<int> nearestGreater(std::vector<int> a) {
    int len = a.size();
    if(len == 0) return {};
    if(len == 1) return {-1};
    vector<int> leftGreater(len);
    vector<int> rightGreater(len);
    vector<int> result(len);    
    leftGreater[0] = -1;
    rightGreater[len - 1] = -1;
    
    for(int i = 1; i < len; i++){
        if(a[i-1] > a[i]){
            leftGreater[i] = i-1;
        } else {
            int k = i-1;
            while(k >= 0 && a[leftGreater[k]] <= a[i]){
                k = leftGreater[k];
            }
            if(k == -1) leftGreater[i] = -1;
            else leftGreater[i] = leftGreater[k];
        }        
    }
    
    for(int i = len - 2; i >= 0; i--){
        if(a[i+1] > a[i]){
            rightGreater[i] = i+1;
        } else {
            int k = i+1;
            while(k >= 0 && a[rightGreater[k]] <= a[i]){
                k = rightGreater[k];
            }
            if(k == -1) rightGreater[i] = -1;
            else rightGreater[i] = rightGreater[k];
        }
    }
    
    for(int i = 0; i < len; i++){
        if(leftGreater[i] == -1) {
            result[i] = rightGreater[i];
        } else if(rightGreater[i] == -1){
            result[i] =  leftGreater[i];
        } else {
            int leftDiff = i - leftGreater[i];
            int rightDiff = rightGreater[i] - i;
            if(leftDiff <= rightDiff){
                result[i] = leftGreater[i];
            } else {
                result[i] = rightGreater[i];
            }
        }
    }

    return result;
}
