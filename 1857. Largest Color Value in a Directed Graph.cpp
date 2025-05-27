class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(vector<int> &e : edges){
            indegree[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }
        vector<vector<int>> t(n, vector<int>(26));
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                t[i][colors[i]-'a']++;
                q.push(i);
            }
        }
        int cnt = 0;
        int ans = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt++;
            ans = max(ans, t[u][colors[u]-'a']);
            for(int v : adj[u]){
                for(int i=0; i<26; i++)
                    t[v][i] = max(t[v][i], t[u][i] + (colors[v]-'a'==i));

                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        if(cnt < n)
            return -1;
        else
            return ans;
    }
};