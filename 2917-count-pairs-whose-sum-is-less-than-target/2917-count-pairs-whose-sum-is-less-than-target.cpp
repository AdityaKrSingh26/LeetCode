class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int l = 0 , h = nums.size()-1;
        while(l<h){
            if(nums[l]+nums[h] < target){
                //If the sum of the elements at l and h is less than the target value, it means all pairs with the current l element will also satisfy the condition.
                ans = ans + (h-l);
                l++;
            }
            else{
                h--;
            }
        }
        return ans;
    }
};