class Solution {
public:
    #define P pair<int,int>
    void dijkstra(int n, vector<vector<P>> & adj, vector<int> &res, int i){
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, i});
        res[i] = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &ngb : adj[node]){
                int dist = ngb.second;
                int adjnode = ngb.first;
                if(d+dist < res[adjnode]){
                    res[adjnode] = d+dist;
                    pq.push({res[adjnode], adjnode});
                }
            }
        }
        for(auto &i : res)
            cout<<i<<" ";
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> spm(n, vector<int>(n, INT_MAX));
        vector<vector<P>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        for(int i=0; i<n; i++)
            dijkstra(n, adj, spm[i], i);

        int res=-1, mn=INT_MAX;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++)
                if(i!=j && spm[i][j] <= distanceThreshold)
                    cnt++;
            if(cnt<=mn){
                mn = cnt;
                res = i;
            }
        }
        return res;
    }
};