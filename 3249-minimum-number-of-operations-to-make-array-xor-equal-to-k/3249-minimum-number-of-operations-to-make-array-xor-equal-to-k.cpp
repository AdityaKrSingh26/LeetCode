class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int temp = 0;
        for(int i=0;i<nums.size();i++)
            temp = temp^nums[i];
        temp = temp^k;
        int count =0;
        for(int i=0;i<31;i++)
            if(temp & (1<<i)) count++;
        return count;
    }
};