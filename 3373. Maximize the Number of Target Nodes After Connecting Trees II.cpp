
class Solution {
public:
    int bfs(vector<vector<int>> & adj, int i){
        queue<int> q;
        q.push(i);
        int n = adj.size();
        vector<int> vis(n);
        int len = 0;
        int cnt = 0;
        while(!q.empty()){
            int s = q.size();
            for(int j=0; j<s; j++){
                int u = q.front();
                q.pop();
                if(len%2 == 0) 
                    cnt++;
                vis[u] = 1;
                for(int v : adj[u]){
                    if(!vis[v])
                        q.push(v);
                }
            }
            len++;
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>> adja(n), adjb(m);
        for(vector<int> &e : edges1){
            adja[e[0]].push_back(e[1]);
            adja[e[1]].push_back(e[0]);
        }
        for(vector<int> &e : edges2){
            adjb[e[0]].push_back(e[1]);
            adjb[e[1]].push_back(e[0]);
        }
        vector<int> res(n, 1);
        int even2 = bfs(adjb, 0);
        int mxb = max(even2, m-even2);
        int even1 = bfs(adja, 0);
        int odd1 = n-even1;
        
        queue<int> q;
        q.push(0);
        vector<int> vis(n);
        int len = 0;
        int cnt = 0;
        while(!q.empty()){
            int s = q.size();
            for(int j=0; j<s; j++){
                int u = q.front();
                q.pop();
                vis[u] = 1;
            
                if(len%2)
                    res[u] = odd1+mxb;
                else
                    res[u] = even1+mxb;
                for(int v : adja[u]){
                    if(!vis[v])
                        q.push(v);
                }
            }
            len++;
        }
        return res;
    }
};