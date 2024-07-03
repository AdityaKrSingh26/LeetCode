class Solution {
public:
    bool possible(vector<int>& nums, int threshold, int mid){
        int count = 0;
        for(int i =0; i<nums.size(); i++){
            count += (nums[i] + mid - 1) / mid;
            if (count > threshold) {
                return false;
            }
        }
        return count<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1 ;
        int high = *max_element(nums.begin(), nums.end());
        while(low<=high)
        {
            int mid = low + (high - low) / 2;
            if(possible(nums,threshold,mid))
                high = mid-1;
            else 
                low = mid+1;
        }
        return low;
    }
};