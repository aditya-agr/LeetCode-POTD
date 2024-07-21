class Solution {
public:
    void dfs(vector<vector<int>>& adj, int i, vector<int> &visited, stack<int> &st, bool &cy){
        visited[i] = 1;
        for(auto &u : adj[i]){
            if(!visited[u])
                dfs(adj, u, visited, st, cy);
            if(visited[u] == 1){
                cy = true;
                return;
            }
        }
        visited[i] = 2;
        st.push(i);
    }
    vector<int> topSort(vector<vector<int>>&mat, int &n){
        vector<vector<int>> adj(n+1);
        for(auto &i : mat)
            adj[i[0]].push_back(i[1]);
        
        vector<int> visited(n+1);
        stack<int> st;
        bool cycle = false;
        for(int i=1; i<=n; i++){
            if(!visited[i])
                dfs(adj, i, visited, st, cycle);
            if(cycle)
                return {};
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> toprow = topSort(rowConditions, k);
        vector<int> topcol = topSort(colConditions, k);

        if(toprow.empty() || topcol.empty())
            return {};
        
        vector<vector<int>> res(k, vector<int>(k));
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                if(toprow[i]==topcol[j])
                    res[i][j] = toprow[i];
            }
        }
        return res;
    }
};