class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            int left = 0;
            int right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (grid[i][mid] < 0) 
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            // All elements from left to n-1 are negative
            ans += (n - left);
        }
        return ans;
    }
};