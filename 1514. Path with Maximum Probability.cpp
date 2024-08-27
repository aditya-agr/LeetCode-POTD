#define P pair<int, double>
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<P>> adj(n);
        int m = edges.size();
        for(int i=0; i<m; i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> res(n);
        res[start_node] = 1;
        priority_queue<P> pq;
        pq.push({start_node, 1});
        while(!pq.empty()){
            int u = pq.top().first;
            double dist = pq.top().second;
            pq.pop();
            for(auto &node : adj[u]){
                int v = node.first;
                double d = node.second;
                if(d*dist > res[v]){
                    res[v] = d*dist;
                    pq.push({v, res[v]});
                }
            }
        }
        return res[end_node];
    }
};