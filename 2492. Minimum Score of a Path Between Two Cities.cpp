class Solution {
public:
    void dfs(int u, vector<vector<pair<int, int>>> &adj, vector<int> &vis){
        vis[u] = 1;
        for(auto &[v, c] : adj[u]){
            if(vis[v])
                continue;
            dfs(v, adj, vis);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(vector<int> &e : roads){
            adj[e[0]-1].push_back({e[1]-1, e[2]});
            adj[e[1]-1].push_back({e[0]-1, e[2]});
        }
        vector<int> vis(n);
        dfs(0, adj, vis);

        int res = INT_MAX;
        for(vector<int> &e : roads){
            int u = e[0]-1;
            int v = e[1]-1;
            if(vis[u] && vis[v])
                res = min(res, e[2]);
        }
        return res;
    }
};