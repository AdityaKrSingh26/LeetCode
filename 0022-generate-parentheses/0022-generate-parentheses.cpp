class Solution {
public:
    void f(vector<string>& v, int open, int close, string str) {
        if (open == 0 && close == 0) {
            v.push_back(str);
            return;
        }
        if (open != 0) 
            f(v, open - 1, close, str+"(");
        if (close > open)
            f(v, open, close - 1, str+")");
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int open = n, close = n;
        string str = "";
        f(v, open, close, str); 
        return v;
    }
};