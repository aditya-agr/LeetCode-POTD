class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k){
        int n = nums.size();
        vector<int> idx(n+1);
        for(int i=0; i<=k; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            idx[l] += val;
            if(r+1<n) idx[r+1] -= val; 
        }
        if(nums[0]>idx[0])
            return false;
        for(int i=1; i<n; i++){
            idx[i] += idx[i-1];
            if(idx[i]<nums[i])
                return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        auto lambda = [](int x){
            return x == 0;
        };
        if(all_of(nums.begin(), nums.end(), lambda))
            return 0;
        int l = 0, h = queries.size()-1;
        int res = -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(nums, queries, mid)){
                res = mid+1;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};