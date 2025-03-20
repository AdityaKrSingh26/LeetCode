class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        for(int i =0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && 
                grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                dfs(nrow, ncol, grid, vis);
            }

        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));

        for(int i=0; i<m;i++){
            if(grid[i][0]==1 && !vis[i][0])
                dfs(i,0,grid,vis);
            if(grid[i][n-1]==1 && !vis[i][n-1])
                dfs(i,n-1,grid,vis);
        }

        for(int i=0; i<n;i++){
            if(grid[0][i]==1 && !vis[0][i])
                dfs(0,i,grid,vis);
            if(grid[m-1][i]==1 && !vis[m-1][i])
                dfs(m-1,i,grid,vis);
        }

        int count =0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};