class Solution {
public:
    pair<int, int> BFS(vector<vector<int>>& adj, int source) {
        queue<int> que;
        que.push(source);
        unordered_map<int, bool> visited;
        visited[source] = true;
        int distance = 0;
        int farthestNode = source;
        while(!que.empty()) {
            int size = que.size(); 
            while(size--) {
                int curr = que.front();
                que.pop();
                farthestNode = curr;
                for(auto &nbr : adj[curr]) {
                    if(visited[nbr] == false) {
                        visited[nbr] = true;
                        que.push(nbr);
                    }
                }
            }
            if(!que.empty()) {
                distance++;
            }
        }
        return {farthestNode, distance};
    }

    int diameter(vector<vector<int>> adj) {
        auto [farthestNode, dist] = BFS(adj, 0);
        auto [otherEndNode, diameter] = BFS(adj, farthestNode);
        return diameter;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        for(vector<int> e : edges1){
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for(vector<int> e : edges2){
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        int d1 = diameter(adj1);
        int d2 = diameter(adj2);
        cout<<d1<<" "<<d2<<"S";
        int d12 = (d1/2) + (d1%2) + (d2/2) + (d2%2) + 1;
        return max(d1, max(d2, d12));

    }
};