class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int ans = 0, l = 1, r = x;
        while (l <= r) {
            int mid = l + (r - l)/2;
            long long val = (long long)mid * mid;
            if(val == x){
                return mid;
            }else if(val <x){
                ans = mid;
                l = mid+1;
            }else{
                r = mid -1;
            }
        }
        return ans;
    }
};