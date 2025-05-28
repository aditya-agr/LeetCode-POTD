class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
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
        if(k==0)
            return res;
        int mxb = 1;
        for(int i=0; i<m; i++){
            queue<int> q;
            q.push(i);
            vector<int> vis(m);
            int len = 0;
            int cnt = 0;
            while(!q.empty() && len<=k-1){
                int s = q.size();
                for(int j=0; j<s; j++){
                    int u = q.front();
                    q.pop();
                    cnt++;
                    vis[u] = 1;
                    for(int v : adjb[u]){
                        if(!vis[v])
                            q.push(v);
                    }
                }
                len++;
            }
            mxb = max(mxb, cnt);
        }
        for(int i=0; i<n; i++){
            queue<int> q;
            q.push(i);
            vector<int> vis(n);
            int len = 0;
            int cnt = 0;
            while(!q.empty() && len<=k){
                int s = q.size();
                for(int j=0; j<s; j++){
                    int u = q.front();
                    q.pop();
                    cnt++;
                    vis[u] = 1;
                    for(int v : adja[u]){
                        if(!vis[v])
                            q.push(v);
                    }
                }
                len++;
            }
            res[i] = cnt+mxb;
        }
        return res;
    }
};