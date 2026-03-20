class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> res(n-k+1, vector<int>(m-k+1, INT_MAX));

        for(int i=0; i<n-k+1; i++){
            for(int j=0; j<m-k+1; j++){
                set<int> st;
                for(int x=i; x<i+k; x++){
                    for(int y=j; y<j+k; y++){
                        st.insert(grid[x][y]);
                    }
                }
                int prev = INT_MIN;
                for(int x : st){
                    if(prev != INT_MIN)
                        res[i][j] = min(res[i][j], x-prev);
                    prev = x;
                }
                if(st.size() == 1)
                    res[i][j] = 0;
            }
        }
        return res;
    }
};