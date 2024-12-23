class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        int prev1 = 1;
        int prev = 1;
        int val = 0;
        for (int i = 1; i < n; i++) {
            val = prev1 + prev;
            prev1 = prev;
            prev = val;
        }
        return val;
    }
};