class Solution {
public:
    string removeZeros(string result) {
        int end = result.size();
        int i = 0;
        while (result[i] == '0')
            i++;
        return result.substr(i, end);
    }
    string removeKdigits(string num, int k) {
        if (num.size() <= k)
            return "0";

        stack<char> st;
        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        cout << result << endl;
        string ans = removeZeros(result);
        if(ans == "")
            return "0";
        return ans;
    }
};