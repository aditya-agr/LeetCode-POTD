class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int m = 1e9+7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> power(n);
        power[0] = 1;
        for(int i=1; i<n; i++)
            power[i] = (power[i-1]*2)%m;
        
        int l = 0;
        int h = n-1;
        int res = 0;
        while(l<=h){
            if(nums[l]+nums[h] <= target){
                int diff = h-l;
                res = (res%m + power[diff])%m;
                l++;
            }
            else
                h--;
        }
        return res;
    }
};