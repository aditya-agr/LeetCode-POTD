class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n), col(m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int i = 0, j = n-1;
        while(i<=j && row[i] == 0) i++;
        while(i<=j && row[j] == 0) j--;
        int l = j-i+1;

        i=0, j=m-1;
        while(i<=j && col[i] == 0) i++;
        while(i<=j && col[j] == 0) j--;
        int b = j-i+1;

        return l*b;
    }
};