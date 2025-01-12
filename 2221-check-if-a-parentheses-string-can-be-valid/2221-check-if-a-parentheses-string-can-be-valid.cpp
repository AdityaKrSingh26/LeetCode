class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0)
            return false;

        int openCnt=0;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0' || s[i] == '(')
                openCnt++;
            else
                openCnt--;
            if (openCnt < 0)
                return false;
        }

        int closeCnt=0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (locked[i] == '0' || s[i] == ')')
                closeCnt++;
            else
                closeCnt--;
            if (closeCnt < 0)
                return false;
        }
        
        return true;
    }
};