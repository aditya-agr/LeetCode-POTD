class Solution {
public:
    int mod = 1e9+7;
    int power(int b, int p){
        if(p==0) return 1;
        if(p==1) return b;
        long long half = power(b, p/2);
        long long res = (half*half)%mod;
        if(p%2)
            res = (res*b)%mod;
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int v = edges.size()+1;
        vector<vector<int>> adj(v);
        for(vector<int> &e : edges){
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        int h = 0;
        queue<int> q;
        vector<int> vis(v);
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                int u = q.front();
                q.pop();
                for(int &v : adj[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
            h++;
        }
        h--;

        return power(2, h-1);
    }
};