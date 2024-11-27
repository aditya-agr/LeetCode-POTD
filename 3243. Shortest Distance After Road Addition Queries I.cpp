class Solution {
public:
    unordered_map<int, vector<int>> adj;

    int bfs(int n){
        queue<int> q;
        vector<int> visited(n);
        q.push(0);
        visited[0] = 1;
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int curr = q.front();
                q.pop();
                if(curr == n-1)
                    return lvl;
                for(int x : adj[curr]){
                    if(visited[x] == 0){
                        q.push(x);
                        visited[x] = 1;
                    }
                }
            }
            lvl++;
        }
        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        adj.clear();
        for(int i=0; i<n-1; i++)
            adj[i].push_back(i+1);
        
        int m = queries.size();
        vector<int> res(m);
        for(int i=0; i<m; i++){
            adj[queries[i][0]].push_back(queries[i][1]);
            res[i] = bfs(n);
        }
        return res;
    }
};