class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for (char ch : s) {
            if ((ch - '0' >= 0 && ch - '0' <= 9) && !st.empty()) {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        string str = "";
        while (!st.empty()) {
            char temp = st.top();
            st.pop();
            str += temp;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};