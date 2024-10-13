class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int x_5 = 0, x_10=0;
        for (auto it : bills) {
            if (it == 5) {
                x_5++;
            } else if (it == 10) {
                if (x_5 > 0) {
                    x_10++;
                    x_5--;
                } else {
                    return false;
                }
            } else if (it == 20) {
                if (x_10 > 0 && x_5 > 0) {
                    x_10--;
                    x_5--;
                } else if (x_5 > 2) {
                    x_5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};