class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int value = 1;
        int rowstart = 0, columnstart = 0, rowend = n - 1, columnend = n - 1;
        while (rowstart <= rowend && columnstart <= columnend) {
            // move right
            for (int i = columnstart; i <= columnend; i++) {
                matrix[rowstart][i] = value;
                value++;
            }
            rowstart++;

            // move down
            for (int i = rowstart; i <= rowend; i++) {
                matrix[i][columnend] = value;
                value++;
            }
            columnend--;

            // move left
            for (int i = columnend; i >= columnstart; i--) {
                matrix[rowend][i] = value;
                value++;
            }
            rowend--;

            // move up
            for (int j = rowend; j >= rowstart; j--) {
                matrix[j][columnstart] = value;
                value++;
            }
            columnstart++;
        }

        // matrix[n/2][n/2]=value;
        return matrix;
    }
};