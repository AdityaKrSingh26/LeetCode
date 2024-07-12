class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
    {
        vector<int> ans;
        for(int i=0; i<queries.size() ;i++)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            int r = queries[i][2];
            int count =0;
            for(int j=0;j<points.size();j++)
            {
                int x1 = points[j][0];
                int y1 = points[j][1];
                if(((x-x1)*(x-x1)) + ((y-y1)*(y-y1)) <= r*r)
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};