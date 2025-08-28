class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> mp;
        int n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int key = i-j;
                mp[key].push_back(grid[i][j]);
            }
        }
        for(int i=0; i<n; i++)
            sort(mp[i].rbegin(), mp[i].rend());
        for(int i=-1; i>-n; i--)
            sort(mp[i].begin(), mp[i].end());

        unordered_map<int, int> idx;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int key = i-j;
                grid[i][j] = mp[key][idx[key]];
                idx[key]++;
            }
        }
        return grid;
    }
};