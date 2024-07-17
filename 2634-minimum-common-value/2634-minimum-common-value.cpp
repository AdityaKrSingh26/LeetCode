class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int mins = INT_MAX;
        unordered_map <int,bool> mpp;
        for(int num:nums1)
            mpp[num] = true;
        for(int num:nums2)
        {
            if(mpp.count(num)>0 && mpp[num] == true)
                mins = min(mins , num);
            mpp[num] = false;
        }
        if(mins==INT_MAX)
            return -1;
        return mins;
    }
};