class Solution {
public:
    long long coloredCells(int n) {
        // long long val = 4, sum =0;
        // for(int i=1;i<n;i++){
        //     sum = sum + val;
        //     val = val+4;
        // }
        // return sum+1;

        // total number of cells at minute n is: 1 + 4 * (n * (n-1) / 2)
        return 1 + 4LL * n * (n - 1) / 2;
    }
};