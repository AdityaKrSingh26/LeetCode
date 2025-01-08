class Solution {
public:
    bool isPrefAndSuff(string s1, string s2){
        int l1 = s1.size();
        int l2 = s2.size();
        if(s2.substr(0,l1) == s1 && s2.substr(l2-l1,l2) == s1)
            return true;
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt =0;
        for(int i=0; i<words.size()-1; i++){
            for(int j=i+1; j<words.size(); j++){
                if(isPrefAndSuff(words[i],words[j]))
                    cnt++;
            }
        }
        return cnt;
    }
};