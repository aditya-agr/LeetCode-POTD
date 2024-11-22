class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            string curr = "";
            int first = matrix[i][0];
            for(int j=0; j<m; j++){
                curr += (matrix[i][j] == first) ? 'S' : 'B';
            }
            mp[curr]++;
        }
        int res = 0;
        for(auto it : mp)
            res = max(res, it.second);   
        return res; 
    }
};