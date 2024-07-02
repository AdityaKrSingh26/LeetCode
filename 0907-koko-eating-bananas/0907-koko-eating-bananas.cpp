class Solution {
public:
    bool possible(vector<int>& piles, int mid, int h) {
        long long count = 0;
        for(int i = 0; i < piles.size(); i++) {
            count += (piles[i] + mid - 1) / mid; // Manually compute the ceiling
            if (count > h) {
                return false; // Early exit if count exceeds h
            }
        }
        return count <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end()); 
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(possible(piles, mid, h)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};