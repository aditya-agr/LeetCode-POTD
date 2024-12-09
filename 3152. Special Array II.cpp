class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> idx(n);
        for(int i=1; i<n; i++){
            idx[i] += idx[i-1];
            if((nums[i]+nums[i-1])%2 == 0)
                idx[i]++;
        }
        int m = queries.size();
        vector<bool> res(m);
        for(int i=0; i<m; i++){
            int st = queries[i][0];
            int ed = queries[i][1];
            res[i] = (idx[ed]-idx[st] == 0);
        }
        return res;
    }
};