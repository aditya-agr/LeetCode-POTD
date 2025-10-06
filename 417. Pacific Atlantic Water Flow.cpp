class Solution {
public:
    vector<vector<int>> dir = {{1,0}, {0,-1}, {-1,0}, {0,1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> isAtlantic(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            q.push({i, m-1});
            isAtlantic[i][m-1] = true;
        }
        for(int i=0; i<m; i++){
            q.push({n-1, i});
            isAtlantic[n-1][i] = true;
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(vector<int> d : dir){
                int i_ = i+d[0];
                int j_ = j+d[1];
                if(i_<n && i_>=0 && j_<m && j_>=0 && isAtlantic[i_][j_]==false && heights[i_][j_]>=heights[i][j]){
                    q.push({i_, j_});
                    isAtlantic[i_][j_] = true;
                    cout<<i<<j<<" "<<i_<<j_<<";";
                }
            }
        }
        
            
        vector<vector<bool>> isPacific(n, vector<bool>(m,false));
        for(int i=0; i<n; i++){
            q.push({i, 0});
            isPacific[i][0] = true;
            }
        for(int i=0; i<m; i++){
            q.push({0, i});
            isPacific[0][i] = true;
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(vector<int> d : dir){
                int i_ = i+d[0];
                int j_ = j+d[1];
                if(i_<n && i_>=0 && j_<m && j_>=0 && isPacific[i_][j_]==false && heights[i_][j_]>=heights[i][j]){
                    q.push({i_, j_});
                    isPacific[i_][j_] = true;
                }
            }
        }
        
        vector<vector<int>> res;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isPacific[i][j] && isAtlantic[i][j])
                    res.push_back({i, j});
            }
        }
        return res;

    }
};