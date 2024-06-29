class Solution {
public:
    void dfs(int node, int curr, vector<vector<int>> &adj, vector<vector<int>> &res){
        for(auto &it : adj[curr]){
            if(res[it].empty() || res[it].back() != node){
                res[it].push_back(node);
                dfs(node, it, adj, res);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n), adj(n);
        for(auto &i : edges)
            adj[i[0]].push_back(i[1]);

        for(int i=0; i<n; i++)
            dfs(i, i, adj, res);
        return res;
    }
};