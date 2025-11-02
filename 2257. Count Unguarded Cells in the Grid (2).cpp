class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> mat(n, vector<char>(m, '0'));
        for(vector<int> g : guards)
            mat[g[0]][g[1]] = 'g';
        for(vector<int> w : walls)
            mat[w[0]][w[1]] = 'w';
        
        for(vector<int> &g : guards){
            int x = g[0];
            int y = g[1];
            for(int i=1; x+i<n && mat[x+i][y]!='g' && mat[x+i][y]!='w'; i++)
                mat[x+i][y] = '1';  
            for(int i=1; x-i>=0 && mat[x-i][y]!='g' && mat[x-i][y]!='w'; i++)
                mat[x-i][y] = '1';  
            for(int i=1; y+i<m && mat[x][y+i]!='g' && mat[x][y+i]!='w'; i++)
                mat[x][y+i] = '1';  
            for(int i=1; y-i>=0 && mat[x][y-i]!='g' && mat[x][y-i]!='w'; i++)
                mat[x][y-i] = '1';  
        }
        int cnt = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(mat[i][j] == '0')
                    cnt++;
        return cnt;
    }
};