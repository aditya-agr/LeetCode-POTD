class Solution {
public:
    bool dfs(int u, vector<vector<int>> &adj, vector<int> &visited, vector<int> &isRecur){
        visited[u] = 1;
        isRecur[u] = 1;

        for(int v : adj[u]){
            if(!visited[v] && dfs(v, adj, visited, isRecur))
                return true;
            else if(isRecur[v])
                return true;
        }
        isRecur[u] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n);
        vector<int> isRecur(n);

        for(int i=0; i<n; i++)
            if(!visited[i])
                dfs(i, graph, visited, isRecur);
        
        vector<int> res;
        for(int i=0; i<n; i++)
            if(!isRecur[i])
                res.push_back(i);

        return res;
    }
};