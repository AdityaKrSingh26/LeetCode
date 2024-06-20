class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //--------  Moore's Voting Algorithm ------
        int el , count = 0;
        for(int i =0; i<nums.size();i++){
            if(count == 0){
                el = nums[i];
                count++;
            }
            else if(nums[i] == el){
                count++;
            }
            else if(nums[i]!= el){
                count--;
            }
        }
        int ct = 0;
        for(int i =0; i<nums.size();i++){
            if(nums[i]==el){
                ct++;
            }
        }
        if(ct > (nums.size()/2))
            return el;
        else
            return -1;

        // ------ hashing ------
        //map<int , int> mpp;
        //for(int i =0; i<nums.size();i++){
        //    mpp[nums[i]]++;
        //}
        //for (auto it :mpp){
        //    if(it.second > (nums.size()/2))
        //        return it.first;
        //}
        //return -1;


    }
};