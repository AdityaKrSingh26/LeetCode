class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> maxfreq(26, 0); 
        for (auto& s : words2) {
            vector<int> freq(26, 0);
            for (char ch : s) {
                freq[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxfreq[i] = max(maxfreq[i], freq[i]);
            }
        }

        // Check each word in words1 to see if it is universal
        for (auto& s : words1) {
            vector<int> freq(26, 0);
            for (char ch : s) {
                freq[ch - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxfreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                ans.push_back(s);
            }
        }

        return ans;
    }
};