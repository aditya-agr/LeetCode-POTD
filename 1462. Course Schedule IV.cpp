class Solution {
public:
    bool dfs(int u, int v, vector<vector<int>> &adj, vector<int>&visited){
        visited[u] = 1;
        if(u == v)
            return true;
        bool ans = false;
        for(int &neb : adj[u]){
            if(!visited[neb])
                ans = ans | dfs(neb, v, adj, visited);
        }
        return ans;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);

        for(vector<int> e : prerequisites)
            adj[e[0]].push_back(e[1]);
        
        vector<bool> res;
        for(vector<int> q : queries){
            int u = q[0];
            int v = q[1];
            vector<int> visited(numCourses);
            bool curr = dfs(u, v, adj, visited);
            res.push_back(curr);
        }
        return res;
    }
};