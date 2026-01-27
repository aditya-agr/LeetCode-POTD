class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for(vector<int> &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], 2*e[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res(n, INT_MAX);
        pq.push({0, 0});
        res[0] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            for(auto &it : adj[u]){
                int v = it.first;
                int d = it.second;
                if(res[v] > d+w){
                    res[v] = d+w;
                    pq.push({res[v], v});
                }
            }
        }
        return res[n-1] == INT_MAX ? -1 : res[n-1];
    }
};