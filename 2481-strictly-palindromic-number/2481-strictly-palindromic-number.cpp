class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }
        long long n, num, digit, rev = 0;
        num = x;
        n = num;
        do{
            digit = num % 10;
            rev = (rev * 10) + digit;
            num = num / 10;
        } while (num != 0);

        if (rev == x)
            return true;
        else
            return false;
    }

    int baseB(int n , int b){
        long long ans = 0, place = 1;
        while(n>0)
        {
            int temp = n%b;
            ans = temp*place + ans;
            place = place *10;
            n = n/b;
        }
    return ans;
}

    bool isStrictlyPalindromic(int n) {
        for(int i = 2 ; i<=n-2 ; i++){
            int temp = baseB(n,i);
            if(!isPalindrome(temp))
                return false;
        }
        return true;
    }
};