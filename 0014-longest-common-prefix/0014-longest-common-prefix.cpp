class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while( j < strs[i].size()) {
                if(temp[j]!=strs[i][j])
                    break;
                j++;
            }
            if(j==0){
                return "";
            }
            temp = temp.substr(0,j);
        }

        return temp;
    }
};