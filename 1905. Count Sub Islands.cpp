class Solution {
public:
    bool check(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        if(i<0 || i>=grid1.size() || j<0 || j>=grid1[0].size())
            return true;
        if(!grid2[i][j])
            return true;
        grid2[i][j] = 0;
        bool res = grid1[i][j];
        res &= check(grid1, grid2, i+1, j);
        res &= check(grid1, grid2, i-1, j);
        res &= check(grid1, grid2, i, j+1);
        res &= check(grid1, grid2, i, j-1);
        return res;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j])
                    res += check(grid1, grid2, i, j);
            }
        }
        return res;
    }
};