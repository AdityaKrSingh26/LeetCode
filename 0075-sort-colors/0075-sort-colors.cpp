class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3] = {0,0,0};
        for(int i =0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        int i = 0;
        while(arr[0]!=0){
            nums[i] = 0;
            arr[0]--;
            i++;
        }
        while(arr[1]!=0){
            nums[i] = 1;
            arr[1]--;
            i++;
        }
        while(arr[2]!=0){
            nums[i] = 2;
            arr[2]--;
            i++;
        }
    }
};