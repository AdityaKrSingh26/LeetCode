class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }

        long long n, num, digit, rev = 0;
        num = x;
        n = num;
        
        do
        {
            digit = num % 10;
            rev = (rev * 10) + digit;
            num = num / 10;
        } while (num != 0);

        if (rev == x){
            return true;
        }
        else{
            return false;
        }
    }
};