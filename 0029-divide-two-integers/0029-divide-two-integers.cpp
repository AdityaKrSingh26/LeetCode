class Solution {
public:
    int divide(int dividend, int divisor) {

         if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;

        bool sign = (dividend > 0) == (divisor > 0);

        // Use long to handle overflow and abs to deal with negatives
        long abs_dividend = labs(dividend);
        long abs_divisor = labs(divisor);

        long quotient = 0;

        // Subtract divisor from dividend as long as possible
        while (abs_dividend >= abs_divisor) {
            long temp = abs_divisor, multiple = 1;
            // Find the largest multiple
            while (abs_dividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            // Subtract that multiple from the dividend
            abs_dividend -= temp;
            quotient += multiple;
        }
        return sign ? quotient : -quotient;
    }
};