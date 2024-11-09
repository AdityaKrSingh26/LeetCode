class Solution {
public:
    double myPow(double x, int n) {
        // ===========Recursion=================
        if (n == 0)
            return 1;
        if (n <= 0) {
            n = abs(n);
            x = 1 / x;
        }
        if (n % 2 == 0) {
            return myPow(x * x, n / 2);
            // for even x^n = (x^2)^n/2
        } else {
            return x * myPow(x, n - 1);
            // for odd x^n = x * x^n-1
        }

        // ============Loop=====================
        // if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        // if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        // double num = 1;
        // if(n>=0){
        //     while(n>0){
        //         num *= x;
        //         n--;
        //     }
        // }
        // else{
        //     n = -n;
        //     while(n>0){
        //         num *= x;
        //         n--;
        //     }
        //     num = 1.0/num;
        // }
        // return num;
    }
};