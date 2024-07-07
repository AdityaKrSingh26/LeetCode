class Solution {
public:
    string reversePrefix(string word, char ch) {

        auto firstOcc = word.find(ch); 
        reverse(word.begin(), word.begin() + firstOcc + 1); 
        return word;

        // string ans = "";
        // int pos , flag =-1;
        // for(int i = 0; i<word.length();i++){
        //     if(word[i] == ch){
        //         pos = i;
        //         flag = 0;
        //         break;
        //     }
        // }
        // if(flag==-1){
        //     return word;
        // }
        // for(int i = pos ; i>=0 ; i--)
        //     ans = ans + word[i];
        
        // for(int i = pos +1; i<word.length();i++)
        //     ans = ans + word[i];
        // return ans;
    }
};