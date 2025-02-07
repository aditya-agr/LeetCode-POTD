class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp, idx;
        int n = queries.size();
        vector<int> res(n);

        for(int i=0; i<n; i++){
            int x = queries[i][0];
            int c = queries[i][1];
            if(idx[x]){
                mp[idx[x]]--;
                if(mp[idx[x]] == 0)
                    mp.erase(idx[x]);
            }
            idx[x] = c;
            mp[c]++;
            res[i] = mp.size();
        }
        return res;
    }
};