class Solution {
public:
    vector<int> minOperations(string boxes) {
        // // Solution: Better
        int n = boxes.size();
        vector<int> lCount(n,0), lCost(n,0);
        vector<int> rCount(n,0), rCost(n,0);
        vector<int> res;
        for(int i = 1; i<n; i++){
            if(boxes[i-1] == '1')
                lCount[i] = lCount[i-1] + 1;
            else 
                lCount[i] = lCount[i-1];
            lCost[i] = lCost[i-1] + lCount[i];
        }
        for(int i = n-2; i>=0; i--){
            if(boxes[i+1] == '1')
                rCount[i] = rCount[i+1] + 1;
            else 
                rCount[i] = rCount[i+1];
            rCost[i] = rCost[i+1] + rCount[i];
        }

        for(int i = 0; i<n; i++)
            res.push_back(rCost[i] + lCost[i]);
        return res;

        // // Solution: Brute-Force
        // int n = boxes.size();
        // vector<int>  res(n, 0);
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++)
        //         if(boxes[j] == '1') res[i] += abs(i-j);
        // }
        // return res;
    }
};