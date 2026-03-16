class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        set<int> st;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                st.insert(grid[i][j]);
                for(int k=1; ;k++){
                    int row = i+2*k;
                    int l = j-k;
                    int r = j+k;
                    if(row >= n || l < 0 || r >= m)
                        break;
                    int sum = 0;
                    int x = i, y = j;
                    for(int t=0; t<k; t++)
                        sum += grid[x+t][y+t];
                    for(int t=0; t<k; t++)
                        sum += grid[x+k+t][y+k-t];
                    for(int t=0; t<k; t++)
                        sum += grid[x+2*k-t][y-t];
                    for(int t=0; t<k; t++)
                        sum += grid[x+k-t][y-k+t];
                    
                    st.insert(sum);
                }
            }
        }
        vector<int> res;
        for(auto it=st.rbegin(); it!=st.rend() && res.size()<3; it++)
            res.push_back(*it);
            
        return res;
    }
};