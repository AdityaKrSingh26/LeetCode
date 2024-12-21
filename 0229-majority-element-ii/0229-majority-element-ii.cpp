class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> a;
        for (int i = 0; i < nums.size(); i++) {
            a[nums[i]]++;
        }
        vector<int> v;
        for (auto it : a) 
            if (it.second > floor(nums.size() / 3)) 
                v.push_back(it.first);
        return v;
    }
};