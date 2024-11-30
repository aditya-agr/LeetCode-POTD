class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;
        for(auto it : pairs){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        int start = pairs[0][0];
        for(auto it : adj){
            int node = it.first;
            if(outdegree[node]-indegree[node] == 1){
                start = node;
                break;
            }
        }

        vector<int> path;
        stack<int> st;
        st.push(start);
        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int nxt = adj[curr].back();
                adj[curr].pop_back();
                st.push(nxt);
            }
            else{
                path.push_back(curr);
                st.pop();
            }
        }

        reverse(path.begin(), path.end());
        vector<vector<int>> res;
        for(int i=0; i<path.size()-1; i++)
            res.push_back({path[i], path[i+1]});
        return res;
    }
};