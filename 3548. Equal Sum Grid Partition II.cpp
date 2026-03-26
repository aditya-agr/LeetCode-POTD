class Solution {
public:
    void reverseRows(vector<vector<int>> &grid){
        int n = grid.size();
        for(int i=0; i<n/2; i++){
            swap(grid[i], grid[n-i-1]);
        }
    }
    void rotate(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> t(m, vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                t[i][j] = grid[j][i];
        }
        for(int i=0; i<m; i++)
            reverse(t[i].begin(), t[i].end());
        
        grid = t;
    }
    bool check(vector<vector<int>> &grid, long long &tot){
        int n = grid.size();
        int m = grid[0].size();
        unordered_set<long long> st;
        long long top = 0;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                st.insert(grid[i][j]);
                top += grid[i][j];
            }
            long long bottom = tot - top;
            long long diff = top - bottom;
            if(grid[0][0]*1LL==diff || grid[0][m-1]*1LL==diff || grid[i][0]*1LL==diff || diff==0LL)
                return true;
            if((i>0 && m>1 && st.count(diff)))
                return true;
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long tot = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                tot += grid[i][j];

        if(check(grid, tot))
            return true;
        reverseRows(grid);
        if(check(grid, tot))
            return true;
        reverseRows(grid);
        rotate(grid);
        if(check(grid, tot))
            return true;
        reverseRows(grid);
        if(check(grid, tot))
            return true;
        return false;
    }
};ss