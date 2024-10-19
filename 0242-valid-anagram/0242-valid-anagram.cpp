class Solution {
public:
    bool isAnagram(string s, string t) {
        int l = s.size(), n = t.size();

        if (l != n)
            return false;

        vector<int> freq(26, 0);
        for (int i = 0; i < l; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for (int count : freq)
            if (count != 0)
                return false;

        return true;
    }
};
