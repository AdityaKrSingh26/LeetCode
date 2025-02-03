class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incMax = 0, decMax = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                cnt++;
                incMax = max(incMax, cnt);
            } else {
                cnt = 0;
            }
        }
        cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                cnt++;
                decMax = max(decMax, cnt);
            } else {
                cnt = 0;
            }
        }

        return max(incMax+1, decMax+1);
    }
};