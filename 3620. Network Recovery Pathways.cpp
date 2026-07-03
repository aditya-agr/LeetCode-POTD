class Solution {
public:
    int res = -1;
    void dfs(int u, int mn, long long sum, vector<int> &vis, vector<bool> &online, long long &k, vector<vector<pair<int, int>>> &adj){
        int n = online.size();
        if(vis[u])
            return;
        if(u == n-1){
            if(sum<=k)
                res = max(res, mn);
            return;
        }
        vis[u] = 1;

        for(auto &it : adj[u]){
            int v = it.first;
            int cost = it.second;
            if(online[v])
                dfs(v, min(mn, cost), sum+cost, vis, online, k, adj);
        }
        vis[u] = 0;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        for(vector<int> &e : edges)
            adj[e[0]].push_back({e[1], e[2]});
        
        vector<int> vis(n, 0);
        dfs(0, INT_MAX, 0LL, vis, online, k, adj);
        return res;
    }
};