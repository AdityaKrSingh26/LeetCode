
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> ans;
        int n = num.size();
        sort(num.begin(), num.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && num[i] == num[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            // Two-pointer approach
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else {
                    // Found a triplet
                    ans.push_back({num[i], num[j], num[k]});
                    // Skip duplicates for the second number
                    while (j < k && num[j] == num[j + 1]) j++;
                    // Skip duplicates for the third number
                    while (j < k && num[k] == num[k - 1]) k--;
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};
