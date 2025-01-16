class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        int l1 = nums1.size(), l2 = nums2.size();

        if (l1 % 2 == 0 && l2 % 2 == 0)
            return 0;

        for (int num : nums1)
            xor1 ^= num;

        for (int num : nums2)
            xor2 ^= num;

        int result = 0;
        if (l2 % 2 == 1)
            result ^= xor1; // nums1 XOR contributes

        if (l1 % 2 == 1)
            result ^= xor2; // nums2 XOR contributes

        return result;
    }
};