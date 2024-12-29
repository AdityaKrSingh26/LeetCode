class Solution {
public:
    // =================== 2D DP ==============================
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Create two 2D dp arrays for the current and next rows
        vector<vector<int>> prev(m, vector<int>(m, 0)),
            curr(m, vector<int>(m, 0));

        // Initialize the last row in prev
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    prev[j1][j2] = grid[n - 1][j1];
                else
                    prev[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        // Fill the dp array from the second last row to the first
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e8;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int value = 0;
                            if (j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            if (j1 + dj1 >= 0 && j1 + dj1 < m &&
                                j2 + dj2 >= 0 && j2 + dj2 < m)
                                value += prev[j1 + dj1][j2 + dj2];
                            else
                                value = -1e8;
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            // Move current row to previous for the next iteration
            prev = curr;
        }

        // The result is stored in prev[0][m - 1]
        return prev[0][m - 1];
    }

    //  ======================== 3D =================================
    int f2(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, 0)));
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e8;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int value = 0;
                            if (j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            if (j1 + dj1 >= 0 && j1 + dj1 < m &&
                                j2 + dj2 >= 0 && j2 + dj2 < m)
                                value += dp[i + 1][j1 + dj1][j2 + dj2];
                            else
                                value = -1e8;
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m - 1];
    }

    // =============== Recursion ====================
    int f(int i, int j1, int j2, int c, int r, vector<vector<int>>& grid) {
        if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
            return -1e8;
        if (i == r - 1) {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        int maxi = -1e8;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int value = 0;
                if (j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];
                value += f(i + 1, j1 + dj1, j2 + dj2, c, r, grid);
                maxi = max(maxi, value);
            }
        }
        return maxi;
    }
};