class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> vis(n, 0);
        vis[0] = 1;
        vis[firstPerson] = 1;
        
        auto comp = [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        };
        sort(meetings.begin(), meetings.end(), comp);
        int m = meetings.size();
        int pt = -1;
        int i=0;
        while(i<m){
            unordered_map<int, vector<int>> adj;
            pt  = meetings[i][2];
            while(i<m && meetings[i][2] == pt){
                int u = meetings[i][0];
                int v = meetings[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
                i++;
            }
            queue<int> q;
            for(auto &it : adj){
                if(vis[it.first])
                    q.push(it.first);
            }
            while(!q.empty()){
                int f = q.front();
                q.pop();
                if(adj.find(f) != adj.end()){
                    for(int x : adj[f]){
                        if(!vis[x]){
                            vis[x] = 1;
                            q.push(x);
                        }
                    }
                }
            }
        }
        vector<int> res;
        for(int i=0; i<n; i++)
            if(vis[i])
                res.push_back(i);
        
        return res;

    }
};