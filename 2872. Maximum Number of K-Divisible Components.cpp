class Solution {
public:
    int dfs(vector<int>& values, int &k, vector<vector<int>>& adj, int &count, int curr, int parent=-1){
        int sum = values[curr];
        for(int x : adj[curr]){
            if (x!=parent)
                sum += dfs(values, k, adj, count, x, curr);
        }
        sum %= k;
        if(sum == 0) count++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(vector<int> &x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int count = 0;
        dfs(values, k, adj, count, 0);
        return count;
    }
};