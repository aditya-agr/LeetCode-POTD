class DSU{
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++)
            parent[i] = i;
    }
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py)
            return;
        if(size[px] < size[py])
            swap(px, py);
        parent[py] = px;
        size[px] += size[py];
    }
    int getSize(int x){
        return size[find(x)];
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        vector<int> degree(n);
        for(vector<int> &e : edges){
            int pu = dsu.find(e[0]);
            int pv = dsu.find(e[1]);
            if(pu != pv)
                dsu.Union(pu, pv);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++)
            mp[dsu.find(i)].push_back(i);
        
        int res = 0;
        for(auto &it : mp){
            bool complete = true;
            int sz = dsu.getSize(it.first);
            for(int v : it.second){
                if(degree[v] != sz-1){
                    complete = false;
                    break;
                }
            }
            if(complete)
                res++;
        }
        return res;
    }
};