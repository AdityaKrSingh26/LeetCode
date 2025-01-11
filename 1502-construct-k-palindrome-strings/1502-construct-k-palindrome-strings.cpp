class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k)
            return false;
        int freq[26] = {0};

        for (char ch : s)
            freq[ch - 'a']++;
        int oddcnt =0;
        for (int i = 0; i < 26; i++)
            if (freq[i] % 2 != 0)
                oddcnt++;

        if(oddcnt>k)
            return false;
        return true;
    }
};