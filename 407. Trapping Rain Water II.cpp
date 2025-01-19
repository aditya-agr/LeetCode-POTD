class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> visited(n, vector<int>(m));
        for(int row=0; row<n; row++){
            for(int col : {0, m-1}){
                visited[row][col] = 1;
                pq.push({heightMap[row][col], row, col});
            }
        }

        for(int col=0; col<m; col++){
            for(int row : {0, n-1}){
                visited[row][col] = 1;
                pq.push({heightMap[row][col], row, col});
            }
        }
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int res = 0;
        while(!pq.empty()){
            vector<int> tp = pq.top();
            pq.pop();
            int height = tp[0];
            int i = tp[1];
            int j = tp[2];
            for(auto x : dir){
                int i_ = i+x[0];
                int j_ = j+x[1];
                if(i_>=0 && i_<n && j_>=0 && j_<m && !visited[i_][j_]){
                    res += max(height - heightMap[i_][j_], 0);
                    visited[i_][j_] = 1;
                    pq.push({max(height,heightMap[i_][j_]), i_, j_});
                }
            }
        }

        return res;
    }
};