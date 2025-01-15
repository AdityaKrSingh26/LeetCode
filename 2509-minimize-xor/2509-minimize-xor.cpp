class Solution {
public:
    int countSetBits(int num) {
        int count = 0;
        while (num) {
            num &= (num - 1);
            count++;
        }
        return count;
    }

    int minimizeXor(int num1, int num2) {
        int count = countSetBits(num2);
        int ans = 0;
        for (int i = 31; i >= 0 && count > 0; i--) {
            if (num1 & (1 << i)) { // If bit `i` is set in `num1`
                ans |= (1 << i);   // Set bit `i` in `ans`
                count--;
            }
        }

        // If there are remaining bits to set, set them from the least significant bit
        for (int i = 0; i <= 31 && count > 0; i++) {
            if (!(ans & (1 << i))) { // If bit `i` is not set in `ans`
                ans |= (1 << i);     // Set bit `i` in `ans`
                count--;
            }
        }

        return ans;
    }
};
