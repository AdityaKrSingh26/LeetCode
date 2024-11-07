class Solution {
public:
    void createSubSec(vector<int> nums, int index , vector<vector<int>>& res, vector<int>& ds)
    {
        if(index==nums.size()){
            res.push_back(ds);
            return;
        }

        ds.push_back(nums[index]);
        createSubSec(nums,index+1,res,ds);
        ds.pop_back();
        createSubSec(nums,index+1,res,ds);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // --------------- Recursion ---------------------
        vector<vector<int>> res;
        vector<int> ds;
        int index=0;
        createSubSec(nums,index,res,ds);
        return res;

        // ----------- Bit Manipulation ------------------
        // vector<vector<int>> ans;
        // int n = nums.size();
        // int subset = 1<<n;
        // for(int i = 0; i <subset ; i++)
        // {
        //     vector<int> curr;
        //     for(int j = 0; j < n; j++)
        //     {
        //         if(i & (1<<j))
        //         {
        //             curr.push_back(nums[j]);
        //         }
        //     }
        //     ans.push_back(curr);
        // }
        // return ans;
    }
};