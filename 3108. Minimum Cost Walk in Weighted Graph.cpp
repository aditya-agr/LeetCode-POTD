class Solution {
    vector<int> parent;
    vector<int> rank;
    vector<int> cost;
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int u, int v, int wt){
        int parent_u = find(u);
        int parent_v = find(v);
        if(parent_u != parent_v){
            if(rank[parent_u] > rank[parent_v]){
                parent[parent_v] = parent_u;
                cost[parent_u] &= cost[parent_v];
                cost[parent_u] &= wt;
            }
            else if(rank[parent_u] < rank[parent_v]){
                parent[parent_u] = parent_v;
                cost[parent_v] &= cost[parent_u];
                cost[parent_v] &= wt;
            }
            else{
                parent[parent_u] = parent_v;
                rank[parent_v]++;
                cost[parent_v] &= cost[parent_u];
                cost[parent_v] &= wt;
            }
        }
        else{
            cost[parent_u] &= wt;
        }
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        cost.resize(n, -1);
        rank.resize(n, 0);
        for(int i=0; i<n; i++)
            parent[i] = i;
        
        for(vector<int> edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            Union(u, v, wt);
        }
        vector<int> res;
        for(vector<int> q : query){
            int u = q[0];
            int v = q[1];
            int parent_u = find(u);
            int parent_v = find(v);
            if(u == v)
                res.push_back(0);
            else if(parent_u == parent_v)
                res.push_back(cost[parent_u]);
            else
                res.push_back(-1);
        }
        return res;
    }
};