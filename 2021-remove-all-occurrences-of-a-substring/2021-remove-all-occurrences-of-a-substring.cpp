class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        int n = s.size();
        int m = part.size();
        for (char ch : s) {
            res += ch;
            if (ch == part[m - 1] && res.size() >= m) {
                if(res.substr(res.size()-m) == part){
                    res.erase(res.size()-m);
                }
            }
        }

        return res;
    }
};