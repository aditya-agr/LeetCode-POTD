
class Solution {
public:
    int countN(int r, vector<vector<int>> &grid){
        int m = grid[0].size();
        int l = 0;
        int h = m-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(grid[r][mid] < 0)
                h = mid-1;
            else   
                l = mid+1;
        }
        return m-l;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        for(int i=0; i<n; i++)
            cnt +=countN(i, grid);
        return cnt;
    }
};