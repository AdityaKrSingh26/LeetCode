class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int l = 0, r = 0, maxi = 0;
        while (r < n) {
            char temp = s[r];
            // If the character is already in the map and within the current window
            if (mp.find(temp) != mp.end() && mp[temp] >= l) {
                l = mp[temp] + 1;
            }
            maxi = max(maxi, r - l + 1);
            mp[temp] = r;
            r++;
        }

        return maxi;
    }
};