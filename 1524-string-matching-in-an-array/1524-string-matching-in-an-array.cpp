class Solution {
public:
    bool contains(string str1, string str2) {
        if (str1.empty()) return true;  // An empty string is a substring of any string
        if (str1.size() > str2.size()) return false; // If str1 is longer, it cannot be a substring

        for (int i = 0; i <= str2.size() - str1.size(); ++i) {
            bool found = true;
            for (int j = 0; j < str1.size(); ++j) {
                if (str2[i + j] != str1[j]) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i == j)
                    continue;
                if (contains(words[i], words[j])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};