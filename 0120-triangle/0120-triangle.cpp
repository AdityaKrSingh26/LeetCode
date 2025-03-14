class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<int> front = triangle[n-1];
        vector<int> curr(n,0);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int d = triangle[i][j] + front[j];
                int dg = triangle[i][j] + front[j + 1];
                curr[j] = min(d, dg);
            }
            front = curr;
        }
        return front[0];
    }

    //  ============== Tabulation ==================
    int f1(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> dp = triangle;
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        // for (int i = 0; i < n; i++)
        //     dp[n - 1][i] = triangle[n - 1][i];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int d = triangle[i][j] + dp[i + 1][j];
                int dg = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(d, dg);
            }
        }
        return dp[0][0];
    }

    // ======== Recursion ==========
    int f(int i, int j, int n, vector<vector<int>>& triangle) {
        if (i == n - 1)
            return triangle[n - 1][j];
        int d = triangle[i][j] + f(i + 1, j, n, triangle);
        int dg = triangle[i][j] + f(i + 1, j + 1, n, triangle);
        return min(d, dg);
    }
};