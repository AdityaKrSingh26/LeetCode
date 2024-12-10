class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void func(string s, int index, vector<string>& p,
              vector<vector<string>>& ans) {
        if (index == s.size()) {
            ans.push_back(p);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                p.push_back(s.substr(index, i - index + 1));
                func(s, i + 1, p, ans);
                p.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> p;
        vector<vector<string>> ans;
        int i = 0;
        func(s, i, p, ans);
        return ans;
    }
};