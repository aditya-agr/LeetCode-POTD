class Solution {
public
    vectorint findMissingAndRepeatedValues(vectorvectorint& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int a, b;
        for(int i=0; in; i++){
            for(int j=0; jm; j++){
                int t = abs(grid[i][j])-1;
                int x = tm;
                int y = t%m;
                if(grid[x][y]  0)
                    a = abs(grid[i][j]);
                else
                    grid[x][y] = -1;
            }
        }
        for(int i=0; in; i++)
            for(int j=0; jm; j++)
                if(grid[i][j]0)
                    b = im+j+1;
                    
        return {a, b};
    }
};