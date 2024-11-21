class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(n, vector<int> (m));
        for(auto w : walls)
            grid[w[0]][w[1]] = 2;

        for(auto g : guards)
            grid[g[0]][g[1]] = 3;
            
        for(auto g : guards){
            int i = g[0], j = g[1];
            while(i>0 && (grid[i-1][j]!=2 && grid[i-1][j]!=3)){
                i--;
                grid[i][j] = 1;
            }
            i = g[0]; j = g[1];
            while(i<n-1 && (grid[i+1][j]!=2 && grid[i+1][j]!=3)){
                i++;
                grid[i][j] = 1;
            }
            i = g[0]; j = g[1];
            while(j>0 && (grid[i][j-1]!=2 && grid[i][j-1]!=3)){
                j--;
                grid[i][j] = 1;
            }
            i = g[0]; j = g[1];
            while(j<m-1 && (grid[i][j+1]!=2 && grid[i][j+1]!=3)){
                j++;
                grid[i][j] = 1;
            }
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 0)
                    cnt++;
        return cnt;
    }
};