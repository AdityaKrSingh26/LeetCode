class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal)
            return true;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            string str = s.substr(i,n+1) + s.substr(0,i);
            // cout << str << endl;
            if(str == goal)
                return true;
        }
        return false;

    }
};