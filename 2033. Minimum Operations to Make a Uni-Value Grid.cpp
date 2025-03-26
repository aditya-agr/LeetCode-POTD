class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> values;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                values.push_back(grid[i][j]);
            
        sort(values.begin(), values.end());
        int k = values.size();
        int median = values[k/2];
        int res = 0;
        for(int val : values){
            if(abs(val - median)%x != 0)
                return -1;
            res += abs(val - median)/x;
        }
        return res;
    }
};