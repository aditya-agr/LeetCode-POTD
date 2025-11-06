class DSU{
  public:
    vector<int> parent, size;
    DSU(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i] = i;
    }
    int find(int x){
        int px = parent[x];
        if(px == x)
            return x;
        return parent[x] = find(px);
    }
    void Union(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py)
            return;
        
        if(size[px]>size[py]){
            parent[py] = px;
            size[px] += size[py]; 
        }
        else{
            parent[px] = py;
            size[py] += size[px]; 
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> ans;
        DSU dsu(c);
        for(vector<int> &con : connections)
            dsu.Union(con[0]-1, con[1]-1);
        
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for(int i=0; i<c; i++){
            int px = dsu.find(i);
            mp[px].push(i);
        }
        vector<int> active(c, 1);
        for(vector<int> &q : queries){
            q[1] -= 1;
            if(q[0] == 1){
                if(active[q[1]] == 1)
                    ans.push_back(q[1]+1);
                else{
                    int px = dsu.find(q[1]);
                    while(!mp[px].empty() && active[mp[px].top()]==0)
                        mp[px].pop();
                    if(mp[px].empty())
                        ans.push_back(-1);
                    else
                        ans.push_back(mp[px].top()+1);
                }
            }
            else
                active[q[1]] = 0;
        }
        return ans;
    }
};