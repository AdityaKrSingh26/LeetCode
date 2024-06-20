class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            int more = target - a;
            if (mpp.find(more) != mpp.end())
            {
                return {mpp[more], i};
            }
            mpp[a] = i;
        }
        return {-1, -1};

        // int l = 0, h = nums.size() - 1;
        // sort(nums.begin(), nums.end());
        // while (l < h)
        // {
        //     int sum = nums[l] + nums[h];
        //     if (sum == target)
        //         return true;
        //     else if (sum > target)
        //         h--;
        //     else
        //         l++;
        // }
        // return false;
    }
};