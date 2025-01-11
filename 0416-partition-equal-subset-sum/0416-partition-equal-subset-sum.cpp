class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

        // Base case: Sum 0 can always be achieved with an empty subset
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        // Base case: Only the first element can form its own value
        if (arr[0] <= target)
            dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (arr[i] <= j)
                    take = dp[i - 1][j - arr[i]];
                dp[i][j] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        return isSubsetSum(nums, target);
    }
};