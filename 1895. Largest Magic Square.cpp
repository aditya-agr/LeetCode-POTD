class Solution {
public:
    vector<vector<int>> rowSum;
    vector<vector<int>> colSum;
    int n, m;
    bool check(int k, vector<vector<int>> &grid){
        
        for(int i=0; i<=n-k; i++){
            for(int j=0; j<=m-k; j++){
                int curRow = rowSum[i][j+k-1] - ((j>0) ? rowSum[i][j-1] : 0);
                int curCol = colSum[i+k-1][j] - ((i>0) ? colSum[i-1][j] : 0);
                bool flag = true;
                for(int r=i; r<i+k && flag; r++){
                    int t = rowSum[r][j+k-1] - ((j>0) ? rowSum[r][j-1] : 0);
                    if(t != curRow)
                        flag = false;
                }
                for(int c=j; c<j+k && flag; c++){
                    int t = colSum[i+k-1][c] - ((i>0) ? colSum[i-1][c] : 0);
                    if(t != curCol)
                        flag = false;
                }
                int d1=0, d2=0;
                int x=i, y=j, z=j+k-1;
                for(int i=0; i<k; i++){
                    d1 += grid[x][y];
                    d2 += grid[x][z];
                    z--;
                    x++;
                    y++;
                }
                if(d1!=d2 || d1!=curRow || d1!=curCol)
                    flag = false;
                if(flag)
                    return true;
            }
        }
        return false;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        rowSum.resize(n, vector<int>(m));
        colSum.resize(n, vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                rowSum[i][j] = grid[i][j];
                colSum[i][j] = grid[i][j];
                if(j>0)
                    rowSum[i][j] += rowSum[i][j-1];
                if(i>0)
                    colSum[i][j] += colSum[i-1][j];
            }
        }
        int k = min(n, m);
        while(k > 1){
            if(check(k, grid))
                return k;
            k--;
        }
        return 1;
    }
};