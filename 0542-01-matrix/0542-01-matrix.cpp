#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1)); 
        // Initialize with -1 (unvisited)
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0; 
                }
            }
        }

        int drow[4] = {-1, 0, +1, 0};
        int dcol[4] = {0, +1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int x = row + drow[i];
                int y = col + dcol[i];

                if(x >= 0 && y >= 0 && x < m && y < n && ans[x][y] == -1) {
                    ans[x][y] = ans[row][col] + 1;
                    q.push({x, y});
                }
            }
        }

        return ans;
    }
};
