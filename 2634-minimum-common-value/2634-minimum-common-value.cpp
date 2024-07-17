class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int maxi = 0 ,i = 0 ,j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                maxi = nums1[i];
                return maxi;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return -1;


        // int mins = INT_MAX;
        // unordered_map <int,bool> mpp;
        // for(int num:nums1)
        //     mpp[num] = true;
        // for(int num:nums2)
        // {
        //     if(mpp.count(num)>0 && mpp[num] == true)
        //         mins = min(mins , num);
        //     mpp[num] = false;
        // }
        // if(mins==INT_MAX)
        //     return -1;
        // return mins;
    }
};