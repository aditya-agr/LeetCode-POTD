class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> a;
        for(int i=30; i>=0; i--){
            int val = (1<<i);
            if(val <= n){
                a.push_back(val);
                n -= val;
            }
        }
        reverse(a.begin(), a.end());
        int m = queries.size();
        int mod = 1e9+7;
        vector<int> res(m, 1);
        for(int j=0; j<m; j++){
            int u = queries[j][0];
            int v = queries[j][1];
            long long val = 1;
            for(int i=u; i<=v; i++){
                val = (val%mod*a[i]%mod)%mod;
            }
            res[j] = val;
        }
        return res;
    }
};ss