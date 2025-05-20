class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> idx(n+1);
        int m = queries.size();
        for(int i=0; i<m; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            idx[l]++;
            idx[r+1]--;
        }
        if(idx[0] < nums[0])
            return false;
        for(int i=1; i<n; i++){
            idx[i] += idx[i-1];
            if(idx[i] < nums[i])
                return false;
        }
        return true;
    }
};