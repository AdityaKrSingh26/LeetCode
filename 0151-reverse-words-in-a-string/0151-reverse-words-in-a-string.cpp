class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res = "";
        string st = "";
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ' && st.size() > 0) {
                ans.push_back(st);
                st.clear();
            } else if (s[i] != ' ') {
                st += s[i];
            }
        }
        if(st.size()>0) 
            ans.push_back(st);
        reverse(ans.begin(),ans.end());
        for (int i = 0; i < ans.size(); i++){
            res = res + ans[i];
            if(i<ans.size()-1)
                res=res+' ';
        }
        cout<<res<<endl;
        return res;
    }
};