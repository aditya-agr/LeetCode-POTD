class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> parent(n);
        int cur = 1;
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i]-nums[i-1] > maxDiff)
                cur++;
            parent[i] = cur;
        }
        int q = queries.size();
        vector<bool> res;
        for(vector<int> &que : queries){
            int u = que[0];
            int v = que[1];
            if(parent[u] == parent[v])
                res.push_back(true);
            else  
                res.push_back(false);
        }
        return res;

    }
};