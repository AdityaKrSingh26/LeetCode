class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // =========== Prefix and suffix ============
        int pre = 1, suff = 1;
        int ans = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (pre == 0)
                pre = 1;
            if (suff == 0)
                suff = 1;
            pre = pre * nums[i];
            suff = suff * nums[n-i-1];

            ans = max(ans, max(pre, suff));
        }
        return ans;

        // if (nums.empty()) return 0;
        // int maxProd = nums[0];
        // int minProd = nums[0];
        // int result = nums[0];
        // for (int i = 1; i < nums.size(); i++) {
        //     // If the current element is negative, swap maxProd and minProd
        //     if (nums[i] < 0)
        //         swap(maxProd, minProd);
        //     // Update the maxProd and minProd
        //     maxProd = max(nums[i], maxProd * nums[i]);
        //     minProd = min(nums[i], minProd * nums[i]);
        //     // Update the result to the maximum value encountered
        //     result = max(result, maxProd);
        // }
        // return result;
    }
};