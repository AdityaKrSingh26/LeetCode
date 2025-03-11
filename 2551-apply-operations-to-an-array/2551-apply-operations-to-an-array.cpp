class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size(), j = 0;
        vector<int> v(n, 0);
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != 0) {
                if (nums[i] == nums[i + 1]) {
                    v[j] = nums[i] * 2;
                    nums[i + 1] = 0;
                    i++;
                } else {
                    v[j] = nums[i];
                }
                j++;
            }
        }
        if(nums[n-1]!=0){
            v[j++] = nums[n-1];
        }
        return v;
    }
};