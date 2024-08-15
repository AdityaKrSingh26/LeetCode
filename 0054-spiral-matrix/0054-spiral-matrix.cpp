class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        int rowend = matrix.size();
        int columnend = matrix[0].size();
        int rowstart = 0, columnstart = 0;
        vector<int> ans;
         while (rowstart < rowend && columnstart < columnend) {
            // Traverse right
            for (int i = columnstart; i < columnend; i++)
                ans.push_back(matrix[rowstart][i]);
            rowstart++;

            // Traverse down
            for (int j = rowstart; j < rowend; j++)
                ans.push_back(matrix[j][columnend - 1]);
            columnend--;

            // Traverse left, only if there's still a row to traverse
            if (rowstart < rowend) {
                for (int i = columnend - 1; i >= columnstart; i--)
                    ans.push_back(matrix[rowend - 1][i]);
                rowend--;
            }

            // Traverse up, only if there's still a column to traverse
            if (columnstart < columnend) {
                for (int j = rowend - 1; j >= rowstart; j--)
                    ans.push_back(matrix[j][columnstart]);
                columnstart++;
            }
        }
        return ans;
    }
};