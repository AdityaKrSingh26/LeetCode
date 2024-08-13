class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
        vector<int> rows(n, 1); // to mark rows to be zeroed
        vector<int> cols(m, 1); // to mark columns to be zeroed

       for(int i=0; i<n ; i++)
       {
            for(int j=0 ; j<m ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
       } 

         // Second pass: zero out the marked rows and columns
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(rows[i] == 0 || cols[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};