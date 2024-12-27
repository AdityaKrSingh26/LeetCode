class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // =================== Optimised ==================
        int n = matrix.size();
        vector<int> temp(n, 0), curr(n, 0);
        curr = matrix[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + curr[j];
                int left = INT_MAX;
                if (j > 0)
                    left = matrix[i][j] + curr[j - 1];
                int right = INT_MAX;
                if (j < n - 1)
                    right = matrix[i][j] + curr[j + 1];

                temp[j] = min(up, min(left, right));
            }
            curr = temp;
        }
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, curr[j]);
        }
        return mini;

        //  ================= Tabulation ===================
        // int n = matrix.size();
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        // dp[0] = matrix[0];
        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         int up = matrix[i][j] + dp[i - 1][j]; // Directly above
        //         int left = INT_MAX;                   // Top-left
        //         if (j > 0)
        //             left = matrix[i][j] + dp[i - 1][j - 1];
        //         int right = INT_MAX; // Top-right
        //         if (j < n - 1)
        //             right = matrix[i][j] + dp[i - 1][j + 1];

        //         dp[i][j] = min(up, min(left, right));
        //     }
        // }

        // int mini = INT_MAX;
        // for (int j = 0; j < n; j++) {
        //     mini = min(mini, dp[n - 1][j]);
        // }
        // return mini;
    }

    // ===================== Recursion ======================
    // int n = matrix.size();
    // int mini = INT_MAX;
    // for (int i = 0; i < n; i++) {
    //     mini = min(mini, f(n - 1, i, n, matrix));
    // }
    // return mini;
    int f(int i, int j, int n, vector<vector<int>>& matrix) {
        // Out of bounds
        if (j < 0 || j >= n)
            return INT_MAX;

        // Base case: top row
        if (i == 0)
            return matrix[0][j];

        // Recursive calculation
        int up = f(i - 1, j, n, matrix);     // From above
        int rd = f(i - 1, j + 1, n, matrix); // From top-right
        int ld = f(i - 1, j - 1, n, matrix); // From top-left

        return matrix[i][j] + min(up, min(ld, rd));
    }
};