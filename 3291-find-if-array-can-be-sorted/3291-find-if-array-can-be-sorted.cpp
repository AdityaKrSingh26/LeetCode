class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1; // Add 1 if the last bit is set
            n >>= 1;        // Right shift n by 1
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        pair<int,int> prev = {INT_MIN,INT_MIN}; // {min,max}
        pair<int,int> curr;
        int prevB =-1;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int b= countSetBits(num);
            if(b != prevB){
                if(curr.first < prev.second)
                    return false;
                prev=curr;
                curr = {num,num};
                prevB=b;
            }
            else{
                curr.first = min(curr.first , num);
                curr.second = max(curr.second , num);
            }
        }
        return curr.first >= prev.second;
        
    }
};