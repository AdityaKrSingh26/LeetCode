class Solution {
public:
    int trap(vector<int>& height) {
        // ===== optimised solution ======
        int n = height.size();
        int lmax = 0, rmax = 0, total = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (lmax > height[l])
                    total += lmax - height[l];
                else
                    lmax = height[l];
                l++;
            } else {
                if (rmax > height[r])
                    total += rmax - height[r];
                else
                    rmax = height[r];
                r--;
            }
        }

        return total;

        // ==== solution 1 =====
        // int n = height.size();
        // if (n == 0)
        //     return 0;
        // vector<int> prefixMax(n), suffixMax(n);
        // prefixMax[0] = height[0];
        // suffixMax[n - 1] = height[n - 1];
        // for (int i = 1; i < n; i++) {
        //     prefixMax[i] = max(prefixMax[i - 1], height[i]);
        // }
        // for (int i = n - 2; i >= 0; i--) {
        //     suffixMax[i] = max(suffixMax[i + 1], height[i]);
        // }
        // int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     ans += max(0, min(prefixMax[i], suffixMax[i]) - height[i]);
        // }
        // return ans;
    }
};
