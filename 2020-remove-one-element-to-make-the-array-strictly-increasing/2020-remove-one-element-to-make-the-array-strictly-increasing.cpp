class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        int ct1 = 0, ct2 = 0;
        int maxi = nums[0];
        int mini = nums[nums.size() - 1];
        for (int i = 1; i < nums.size(); i++)
        {
            if (maxi >= nums[i])
            {
                ct1++;
            }
            maxi = max(maxi, nums[i]);
        }
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (mini <= nums[i])
            {
                ct2++;
            }
            mini = min(mini, nums[i]);
        }

        //if any side traversal have only one or zero discontinuity then return true because after removing singular discontinuity array can be made strictly increasing
        if(ct1==1||ct1==0||ct2==1||ct2==0) 
            return true;
        else
            return false;
    }
};