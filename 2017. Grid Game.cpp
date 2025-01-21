class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long row0 = 0;
        long long row1 = 0;
        for(int i=0; i<n; i++)
            row0 += grid[0][i];
        long long res = LLONG_MAX;
        for(int i=0; i<n; i++){
            row0 -= grid[0][i];
            res = min(res, max(row0, row1));
            row1 += grid[1][i];
        }
        return res;
    }
};