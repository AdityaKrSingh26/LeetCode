class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> neg, pos;
        for(auto num : nums){
           if(num < 0) 
                neg.push_back(num);
           else 
                pos.push_back(num);
        }
        vector<int> result;
        int nIndx = 0, pIndx = 0;
        while(nIndx < neg.size() && pIndx < pos.size())
        {
            result.push_back(pos[pIndx++]);
            result.push_back(neg[nIndx++]);
        }
        return result;
    }
};