class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int v : asteroids) {
            int curr = v;
            while (!ans.empty() && ans.back() > 0 && curr < 0) {
                if (ans.back() < abs(curr)) {
                    ans.pop_back();
                    continue;
                } else if (ans.back() == abs(curr)) {
                    ans.pop_back();
                }
                curr = 0;
            }
            if (curr != 0)
                ans.push_back(curr);
        }
        return ans;
    }
};