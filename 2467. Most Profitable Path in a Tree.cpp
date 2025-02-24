class Solution {
public:
    unordered_map<int, int> mpb;
    vector<vector<int>> adj;
    int maxIncome;
    void dfsAlice(int u, int p, int d, int &curr, vector<int >&amount){
        int tmp = 0;
        if(mpb.find(u) == mpb.end() || mpb[u] > d)
            tmp = amount[u];
        else if(mpb[u] == d)
            tmp = (amount[u]/2);
        curr += tmp;
        if(adj[u].size() == 1 && u != 0)
            maxIncome = max(maxIncome, curr);

        for(int v : adj[u]){
            if(v == p) continue;
            dfsAlice(v, u, d+1, curr, amount);
        }
        curr -= tmp;
    }
    bool dfsBob(int u, int p, int d){
        mpb[u] = d;
        if(u == 0)
            return true;
        for(int v : adj[u]){
            if(v==p) continue;
            if(dfsBob(v, u, d+1))
                return true; 
        }
        mpb.erase(u);
        return false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n);
        for(vector<int> edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfsBob(bob, -1, 0);
        int income = 0;
        maxIncome = INT_MIN;
        dfsAlice(0, -1, 0, income, amount);
        return maxIncome;
    }
};