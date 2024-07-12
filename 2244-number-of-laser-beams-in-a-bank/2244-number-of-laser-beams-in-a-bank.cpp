class Solution {
public:
    int getOnes( string str)
    {
        int ones = 0;
        for(int i =0;i<str.size();i++)
            if( str[i] == '1') ones += 1;
        return ones;
    }
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        for( int i = 0; i < bank.size() ; i++ )
        {
            int current = getOnes(bank[i]); 
            if(current != 0)
            {
                ans += current * prev;
                prev = current;
            }
        }
        return ans;   
    }
};