class Solution {
public:
    void subSec(vector<int>& candidates, int index, vector<vector<int>>& res,
                vector<int>& ds, int target) {
        if (index == candidates.size()) {
            if (target == 0)
                res.push_back(ds);
            return;
        }

        // Take the current candidate if it doesn't exceed the target
        if (candidates[index] <= target) {
            ds.push_back(candidates[index]);
            subSec(candidates, index, res, ds, target - candidates[index]);
            ds.pop_back();
        }
        // Skip the current candidate and move to the next
        subSec(candidates, index + 1, res, ds, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        subSec(candidates, 0, res, ds, target);
        return res;
    }
};
