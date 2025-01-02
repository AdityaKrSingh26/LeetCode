class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans,
             vector<vector<int>>& image, int iniColor, int color) {
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
                image[nrow][ncol] == iniColor && ans[nrow][ncol] != color) {
                dfs(nrow, ncol, ans, image, iniColor, color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, iniColor, color);
        return ans;
    }
};