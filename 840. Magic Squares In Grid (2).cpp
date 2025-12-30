class Solution {
public:
    bool check(int r, int c, vector<vector<int>>& grid){
        vector<int> row(3), col(3);
        int d1=0, d2=0;
        vector<int> cnt(10);
        for(int i=r; i<r+3; i++){
            for(int j=c; j<c+3; j++){
                if(grid[i][j]>0 && grid[i][j]<=9)
                    cnt[grid[i][j]]++;
                else
                    return false;
                row[i-r] += grid[i][j];
                col[j-c] += grid[i][j];
                if(i-r == j-c){
                    d2 += grid[i][c+2-j+c];
                    d1 += grid[i][j]; 
                }
            }
        }
        if(d1!=15 || d2!=15)
            return false;
        for(int i=1; i<10; i++)
            if(!cnt[i])
                return false;
        for(int i=0; i<3; i++)
            if(row[i]!=15 || col[i]!=15)
                return false;

        return true;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0; i<n-2; i++){
            for(int j=0; j<m-2; j++){
                if(check(i, j, grid))
                    cnt++;
            }
        }
        return cnt;
    }
};