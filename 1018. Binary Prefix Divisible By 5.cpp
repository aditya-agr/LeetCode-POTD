class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int x = 0;
        int n = nums.size();
        vector<bool> res(n);
        for(int i=0; i<n; i++){
            x = x*2 + nums[i];
            res[i] = (x%5 == 0);
            x = x%5;
        }
        return res;
    }
};