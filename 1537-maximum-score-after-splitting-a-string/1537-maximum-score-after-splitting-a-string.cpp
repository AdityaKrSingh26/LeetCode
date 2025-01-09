class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '1')
                right++;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n - 1; i++) { 
            if (s[i] == '0')
                left++;
            else
                right--;

            maxi = max(maxi, left + right);
        }

        return maxi;
    }
};