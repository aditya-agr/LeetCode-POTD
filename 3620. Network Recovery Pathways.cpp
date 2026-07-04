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


----------------------------------------------------------------------------------------------


class Solution {
public:
    bool check(int mid, vector<vector<pair<int, int>>> &adj, long long &k, vector<bool> &online, vector<int> &topo){
        int n = online.size();
        vector<long long> dp(n, LLONG_MAX/2);
        dp[0] = 0;
        for(int &u : topo){
            for(auto &it : adj[u]){
                int v = it.first;
                long long c = it.second;
                if(c<mid || !online[v])
                    continue;
                if(c+dp[u] < dp[v])
                    dp[v] = c + dp[u];
            }
        }
        return dp[n-1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> indegree(n);
        for(vector<int> &e : edges){
            indegree[e[1]]++;
            adj[e[0]].push_back({e[1], e[2]});
        }
        queue<int> q;
        for(int i=0; i<n; i++)
            if(!indegree[i])
                q.push(i);
        
        vector<int> topo;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for(auto &it : adj[u]){
                int v = it.first;
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        int l = 0, h = 1e9;
        int res = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(check(mid, adj, k, online, topo)){
                res = max(res, mid);
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return res;
    }
};