class Solution {
public:
    void bfs(vector<vector<int>> &adj, int u, vector<int> &nodes, vector<bool> &visited){
        queue<int> q;
        q.push(u);
        int n = adj.size();
        while(!q.empty()){
            int no = q.front();
            q.pop();
            visited[no] = true;
            nodes.push_back(no);
            for(int i=0; i<n; i++){
                if(adj[no][i] && !visited[i])
                    q.push(i);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>(n));
        for(vector<int> &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        vector<bool> visited(n);
        int res = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                vector<int> nodes;
                bfs(adj, i, nodes, visited);
                bool flag = true;
                for(int u : nodes){
                    for(int v : nodes){
                        if(u == v) continue;
                        if(!adj[u][v])
                            flag = false;
                    }
                }
                if(flag)
                    res++;
            }
        }
        return res;
    }
};