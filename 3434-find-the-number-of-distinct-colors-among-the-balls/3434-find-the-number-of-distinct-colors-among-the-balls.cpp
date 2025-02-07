class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball, color;
        vector<int> ans;
        int distinct = 0;

        for (auto& q : queries) {
            int pos = q[0], c = q[1];

            // Remove old color if it exists
            if (ball.count(pos) && --color[ball[pos]] == 0) {
                color.erase(ball[pos]);
                distinct--;
            }

            // Assign new color
            ball[pos] = c;
            if (++color[c] == 1) distinct++;

            ans.push_back(distinct);
        }
        return ans;
    }
};
