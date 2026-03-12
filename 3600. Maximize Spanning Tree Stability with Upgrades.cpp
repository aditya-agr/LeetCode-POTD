class DSU{
    vector<int> parent, rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
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
        if(rank[px] > rank[py])
            parent[py] = px;
        else if(rank[px] < rank[py])
            parent[px] = py;
        else{
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    bool check(int n, vector<vector<int>>& edges, int mid, int k){
        DSU dsu(n);
        vector<vector<int>> upgradeEdges;
        for(vector<int> &e : edges){
            int u = e[0];
            int v = e[1];
            int s = e[2];
            int m = e[3];
            if(m == 1){
                if(s < mid)
                    return false;
                dsu.Union(u, v);
            }
            else{
                if(s >= mid)
                    dsu.Union(u, v);
                else if(2*s >= mid)
                    upgradeEdges.push_back({u, v});
            }
        }
        for(vector<int> &e : upgradeEdges){
            int pu = dsu.find(e[0]);
            int pv = dsu.find(e[1]);
            if(pu == pv)
                continue;
            if(k == 0)
                break;
            dsu.Union(e[0], e[1]);
            k--;
        }
        int root = dsu.find(0);
        for(int i=1; i<n; i++)
            if(dsu.find(i) != root)
                return false;
        
        return true;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        for(vector<int> &e : edges){
            if(e[3] == 1){
                int pu = dsu.find(e[0]);
                int pv = dsu.find(e[1]);
                if(pu == pv)
                    return -1;
                dsu.Union(e[0], e[1]);
            }
        }
        int l=1, h=2*1e5;
        int res=-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(n, edges, mid, k)){
                res = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return res;
    }
};s