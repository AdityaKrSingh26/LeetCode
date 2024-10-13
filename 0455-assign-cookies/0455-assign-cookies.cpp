class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int pg = 0, ps = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (ps < s.size() && pg < g.size()) {
            if (s[ps] >= g[pg]) {
                pg++;
            }
            ps++;
        }
        return pg;
    }
};