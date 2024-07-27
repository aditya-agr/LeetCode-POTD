class Solution {
public:
    void dijkstra(char &c, unordered_map<char, vector<pair<char, int>>> &adj, vector<vector<int>> &cm){
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        pq.push({0, c});
        cm[c-'a'][c-'a'] = 0;
        while(!pq.empty()){
            char node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto &it : adj[node]){
                int dist = it.second;
                char adjnode = it.first;
                if(cm[c-'a'][adjnode-'a'] > d+dist){
                    cm[c-'a'][adjnode-'a'] = d+dist;
                    pq.push({d+dist, adjnode});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        unordered_map<char, vector<pair<char, int>>> adj;
        for(int i=0; i<n; i++)
            adj[original[i]].push_back({changed[i], cost[i]});

        vector<vector<int>> cm(26, vector<int>(26,INT_MAX));
        for(char &c : source)
            dijkstra(c, adj, cm);

        int m = source.size();
        long long res=0;
        for(int i=0; i<m; i++){
            if(cm[source[i]-'a'][target[i]-'a'] != INT_MAX)
                res += cm[source[i]-'a'][target[i]-'a'];
            else
                return -1;
        }

        return res;
    }
};