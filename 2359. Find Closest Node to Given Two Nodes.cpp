class Solution {
public:
    vector<int> minDistance(vector<vector<int>> &adj, int u){
        int m = adj.size();
        queue<int> q;
        q.push(u);
        vector<int> res(m, -1);
        vector<int> vis(m);
        int len = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                int node = q.front();
                q.pop();
                vis[node] = 1;
                res[node] = len;
                for(int v : adj[node])
                    if(!vis[v])
                        q.push(v);
            }
            len++;
        }
        return res;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++)
            if(edges[i]!=-1) 
                adj[i].push_back(edges[i]);
        
        vector<int> vis(n);
        vector<int> a = minDistance(adj, node1);
        vector<int> b = minDistance(adj, node2);
        int res = INT_MAX;
        int ans = -1;
        for(int i=0; i<n; i++){
            if(a[i]!=-1 && b[i]!=-1 && max(a[i], b[i]) < res){
                res = max(a[i], b[i]);
                ans = i;
            }
        }
        return ans;
    }
};