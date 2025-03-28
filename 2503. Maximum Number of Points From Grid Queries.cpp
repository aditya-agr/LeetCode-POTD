class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();

        int Q = queries.size();
        vector<int> res(Q, 0);

        vector<pair<int,int>> sorted(Q);
        for(int i=0; i<Q; i++)
            sorted[i] = {queries[i], i};

        sort(sorted.begin(), sorted.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[0][0] = true;

        int point = 0;
        for(int i=0; i<Q; i++){
            int query = sorted[i].first;
            int idx = sorted[i].second;
            while(!pq.empty() && pq.top()[0] < query){
                int i = pq.top()[1];
                int j = pq.top()[2];
                point++;
                pq.pop();
                for(vector<int> &dir : directions){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if(j_<m && j_>=0 && i_<n && i_>=0 && !vis[i_][j_]){
                        pq.push({grid[i_][j_], i_, j_});
                        vis[i_][j_] = true;
                    }
                }
            }
            res[idx] = point;
        }
        return res;
    }
};