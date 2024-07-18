class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int count = 0, prevcount=0; 
        for(int i=0; i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
                count++;
                prevcount = max(count,prevcount);
            }else if(s[i]==')'){
                count--;
            }
        }
        return prevcount;
    }
};