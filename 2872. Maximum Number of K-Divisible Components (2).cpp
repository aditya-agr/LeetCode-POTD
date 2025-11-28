class Solution {
public:
    int count, K;
    int solve(int p, int u, int sum, vector<vector<int>> &adj, vector<int>& values){
        sum = values[u];
        for(int v : adj[u]){
            if(v == p)
                continue;
            sum += solve(u, v, sum, adj, values);
        }
        sum %= K;
        if(sum == 0)
            count++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        count = 0;
        K = k;
        vector<vector<int>> adj(n);
        for(vector<int> e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int sum = 0;
        solve(-1, 0, sum, adj, values);
        return count;
    }
};