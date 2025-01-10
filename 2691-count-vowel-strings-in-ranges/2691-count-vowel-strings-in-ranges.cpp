class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size(), l = queries.size();
        vector<int> v(n + 1, 0), ans;
        for (int i = 1; i <= n; i++) {
            string s = words[i-1];
            int x = s.size();
            if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' ||
                 s[0] == 'u') &&
                (s[x - 1] == 'a' || s[x - 1] == 'e' || s[x - 1] == 'i' ||
                 s[x - 1] == 'o' || s[x - 1] == 'u')) {
                v[i] = v[i - 1] + 1;
            }else{
                v[i] = v[i-1];
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            int temp = v[queries[i][1]+1] - v[queries[i][0]];
            ans.push_back(temp);
        }
        return ans;
    }
};