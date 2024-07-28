class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> d1(n+1, INT_MAX);
        vector<int> d2(n+1, INT_MAX);

        queue<pair<int, int>> q;
        q.push({1, 1});
        d1[1] = 0;

        while(!q.empty()){
            auto [node, freq] = q.front();
            q.pop();
            int timp = (freq==1) ? d1[node] : d2[node];
            if(node == n && d2[node] != INT_MAX)
                return d2[n];
            int div = timp/change;
            if(div%2)
                timp = (div+1)*change;
            for(auto &ngb : adj[node]){
                if(d1[ngb] == INT_MAX){
                    d1[ngb] = timp+time;
                    q.push({ngb, 1});
                }
                else if(d2[ngb] == INT_MAX && d1[ngb] != timp+time){
                    d2[ngb] = timp+time;
                    q.push({ngb, 2});
                }
            }
        }
        return -1;
    }
};