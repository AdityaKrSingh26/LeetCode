class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // Split 4 into pairs of 2's
        // use a hashmap to track product frequencies pairwise.
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int p = nums[i] * nums[j];
                ans += 8 * mp[p];
                mp[p]++;
            }
        }
        return ans;
    }
};