class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt =0, l=pref.size();
        for(int i=0; i<words.size();i++)
            if(words[i].substr(0,l) == pref)
                cnt++;
        return cnt;
    }
};