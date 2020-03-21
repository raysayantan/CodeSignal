/*
You have a 2D binary matrix that's filled with 0s and 1s. In the matrix, find the largest square that contains only 1s and return its area.

Example

For

matrix = [
    ['1', '0', '1', '1', '1'],
    ['1', '0', '1', '1', '1'],
    ['1', '1', '1', '1', '1'],
    ['1', '0', '0', '1', '0'],
    ['1', '0', '0', '1', '0']
]
the output should be
maximalSquare(matrix) = 9.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.array.char matrix

Guaranteed constraints:
0 ≤ matrix.length ≤ 100,
1 ≤ matrix[i].length ≤ 100,
0 ≤ matrix[i][j] ≤ 1.

[output] integer

An integer that represents the area of the largest square in the given matrix that is composed only of 1s.
*/
int maximalSquare(std::vector<std::vector<char>> matrix) {
    int maxSquare = 0;
    int row = matrix.size();
    int col = (matrix[0]).size();
    if(row == 0) return 0;
    vector<vector<unsigned int>> sqrMatrix(row);
    for(int i = 0; i < row; i++){
        sqrMatrix[i] = vector<unsigned int>(col);
    }
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == 0 || j == 0) {
                if(maxSquare == 0) maxSquare = matrix[i][j] - '0';
                sqrMatrix[i][j] = matrix[i][j] - '0';
                continue;
            }
            else if(matrix[i][j] != '0'){
                if(maxSquare == 0) maxSquare = matrix[i][j] - '0';
                if(sqrMatrix[i-1][j-1] != 0){
                    int temp = sqrt(sqrMatrix[i-1][j-1]);
                    int sqrCnt = 1;
                    for(int k = i - 1, l = j - 1; k >= (i - temp) && l >= (j - temp); k--, l--){
                        if((k < 0 || sqrMatrix[k][j] == 0) || (l < 0 || sqrMatrix[i][l] == 0)){
                            break;
                        } else sqrCnt++;
                    }
                    sqrMatrix[i][j] = sqrCnt*sqrCnt;
                    if(sqrMatrix[i][j] > maxSquare) maxSquare = sqrMatrix[i][j];
                } else {
                    sqrMatrix[i][j] = matrix[i][j] - '0';
                }
            } else {
                sqrMatrix[i][j] = matrix[i][j] - '0';
            }
        }
    }
    return maxSquare;
}
