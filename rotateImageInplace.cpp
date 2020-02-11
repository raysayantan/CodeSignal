/*
Note: Try to solve this task in-place (with O(1) additional memory), since this is what you'll be asked to do during an interview.

You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).

Example

For

a = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
the output should be

rotateImage(a) =
    [[7, 4, 1],
     [8, 5, 2],
     [9, 6, 3]]
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.array.integer a

Guaranteed constraints:
1 ≤ a.length ≤ 100,
a[i].length = a.length,
1 ≤ a[i][j] ≤ 104.

[output] array.array.integer
*/
std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
    int l = a.size();

    //Transpose of the matrix
    int startCol = 1;
    for(int row = 0; row < l; row++){
        for(int col = startCol; col < l; col++){
           int temp = a[row][col];
           a[row][col] = a[col][row];
           a[col][row] = temp;
        }
        startCol++;
    }

    //reversing the columns
    for(int col = 0; col < l; col++){
        if(col < l - col - 1){
            for(int row = 0; row < l; row++){
                int temp = a[row][col];
                a[row][col] = a[row][l - col -1];
                a[row][l - col - 1] = temp;
            }
        }
    }

    return a;
}
