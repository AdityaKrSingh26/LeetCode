class Solution {
public:
    int M = 1e9 + 7;
    long long power(long long x , long long y){
        if(y==0)
            return 1;
        long long ans = power(x,y/2);
        ans *= ans;
        ans = ans%M;
        if(y%2!=0)
            ans*=x;
        ans = ans%M;
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long cnt4s = n/2;
        long long cnt5s = n-cnt4s;
        long long ans = ((power(5,cnt5s)*power(4,cnt4s))%M);
        return (int)ans;
    }
};