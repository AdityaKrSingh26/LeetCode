class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,bool> mpp;
        for(int num:nums1)
            mpp[num] = true;
        for(int num : nums2){
            if(mpp.count(num)>0 && mpp[num] ==true)
                ans.push_back(num);
            mpp[num]=false;
        }
        return ans;
    }
};