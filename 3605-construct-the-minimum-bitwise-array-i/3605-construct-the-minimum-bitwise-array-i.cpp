class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            int num = nums[i];

            for (int a = 0; a < num; ++a) {
                if ((a | (a + 1)) == num) {
                    ans[i] = a;
                    break;
                }
            }
        }

        return ans;
    }
};