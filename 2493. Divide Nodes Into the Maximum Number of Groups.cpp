class Solution {
public:
    bool isBipartite(vector<vector<int>> &adj, vector<int> &colors, int u, int c){
        colors[u] = c;

        for(int &neg : adj[u]){
            if(colors[neg] == colors[u])
                return false;
            if(colors[neg] == -1){
                if(isBipartite(adj, colors, neg, 1-c) == false)
                    return false;
            }
        }
        return true;
    }
    int bfs(vector<vector<int>> &adj, int node, int n){
        queue<int> q;
        vector<int> vis(n);
        vis[node] = 1;
        q.push(node);
        int lvl = 1;
        while(!q.empty()){
            int sze = q.size();
            while(sze--){
                int ft = q.front();
                q.pop();
                for(int &neg : adj[ft]){
                    if(vis[neg]) continue;
                    q.push(neg);
                    vis[neg] = 1;
                }
            }
            lvl++;
        }
        return lvl-1;
    }
    int findmax(int i, vector<vector<int>> &adj, vector<int> &levels, vector<bool> &vis){
        queue<int> q;
        q.push(i);
        int res = 0;
        while(!q.empty()){
            int ft = q.front();
            q.pop();
            vis[ft] = 1;
            res = max(res, levels[ft]);
            for(int &neg : adj[ft]){
                if(!vis[neg])
                    q.push(neg);
            }
        }
        return res;

    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int> e : edges){
            int u = e[0]-1;
            int v = e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colors(n,-1);
        for(int i=0; i<n; i++){
            if(colors[i] == -1)
                if(isBipartite(adj, colors, i, 1) == false)
                    return -1;
        }
        vector<int> levels(n);
        for(int i=0; i<n; i++){
            levels[i] = bfs(adj, i, n);
        }
        
        int maxGroup = 0;
        vector<bool> vis(n);
        for(int i=0; i<n; i++){
            if(!vis[i])
                maxGroup += findmax(i, adj, levels, vis);
        }
        return maxGroup;
    }
};