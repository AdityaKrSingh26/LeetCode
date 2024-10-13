class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int x_5 = 0, x_10 = 0;
        for (int bill : bills) {
            if (bill == 5) {
                x_5++;
            } else if (bill == 10) {
                if (x_5 == 0) return false;
                x_5--;
                x_10++;
            } else {
                if (x_10 > 0 && x_5 > 0) {
                    x_10--;
                    x_5--;
                } else if (x_5 >= 3) {
                    x_5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
