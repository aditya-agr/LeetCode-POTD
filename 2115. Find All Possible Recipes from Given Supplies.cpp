class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> st(supplies.begin(), supplies.end());
        unordered_map<string, vector<int>> adj;
        vector<int> indegree(n);

        for(int i=0; i<n; i++){
            for(string &ing : ingredients[i]){
                if(!st.count(ing)){
                    adj[ing].push_back(i);
                    indegree[i]++;
                }
            }
        }
        queue<string> que;
        for(int i=0; i<n; i++){
            if(!indegree[i])
                que.push(recipes[i]);
        }
        vector<string> res;
        while(!que.empty()){
            string cur = que.front();
            que.pop();
            res.push_back(cur);
            for(int &idx : adj[cur]){
                indegree[idx]--;
                if(indegree[idx] == 0)
                    que.push(recipes[idx]);
            }
        }
        return res;
    }
};