class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> row(n), col(m);

        long long tot = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                row[i] += grid[i][j];
                col[j] += grid[i][j];
                tot += grid[i][j];
            }
        }
        if(tot%2)
            return false;
        long long cur = 0;
        for(int i=0; i<n; i++){
            cur += row[i];
            if(cur == tot/2)
                return true;
        }
        cur = 0;
        for(int j=0; j<m; j++){
            cur += col[j];
            if(cur == tot/2)
                return true;
        }
        return false;
    }
};