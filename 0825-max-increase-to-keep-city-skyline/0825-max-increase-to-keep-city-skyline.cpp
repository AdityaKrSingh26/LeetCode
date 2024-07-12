class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
    {
        // create 2 vectors to store the row max and column max
        vector<int> rowmax;
        vector<int> colmax;
        int n = grid.size();
        for(int i = 0;i<n;i++){
            int rmx = INT_MIN;
            int cmx = INT_MIN;
            for(int j = 0;j<n;j++){
                if(grid[i][j]>rmx) 
                    rmx = grid[i][j];
                if(grid[j][i]>cmx) 
                    cmx = grid[j][i];
            }
            rowmax.push_back(rmx);
            colmax.push_back(cmx);
        }

        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               count += min(abs(grid[i][j]-rowmax[i]),abs(grid[i][j]-colmax[j])); 
            }
        }
        return count;
    }
};