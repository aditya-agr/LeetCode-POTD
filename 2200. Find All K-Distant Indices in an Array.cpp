class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> res;
        int idx = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == key){
                int mn = max(idx+1, max(0, i-k));
                int mx = min(n-1, i+k);
                for(int i=mn; i<=mx; i++)
                    res.push_back(i);
                idx = mx;
            }
        }
        return res;
    }
};