class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 0; i < n; i++) {
            int take = nums[i];
            if (i > 1)
                take = take + prev2;

            int notTake = 0 + prev;
            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    // ===== Recursion =====
    // int robHelper(const vector<int>& nums, int index) {
    //     if (index >= nums.size())
    //         return 0;
    //     int robCurrent = nums[index] + robHelper(nums, index + 2);
    //     int skipCurrent = robHelper(nums, index + 1);
    //     return max(robCurrent, skipCurrent);
    // }
    // int rob(vector<int>& nums) {
    //     return robHelper(nums, 0);
    // }
};