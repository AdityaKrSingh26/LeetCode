class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        int flag = 1, i = 0;
        while (i < s.size() && s[i] == ' ') 
            i++;


        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            flag = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.size()) {
            int x = s[i] - '0';
            if (x < 0 || x > 9)
                break;
            ans = ans * 10 + x;

            if (ans * flag > INT_MAX) 
                return INT_MAX;
            
            if (ans * flag < INT_MIN) 
                return INT_MIN;
            i++;
        }
        return ans * flag;
    }
};