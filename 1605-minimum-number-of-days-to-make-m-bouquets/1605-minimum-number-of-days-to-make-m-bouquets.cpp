class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k , int day){
        int count =0 , nof = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
            }else{
                nof += (count/k);
                count = 0;
            }
        }
        nof += (count/k);
        return nof>=m;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = (long long)k * m;
        if (total > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, m, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};