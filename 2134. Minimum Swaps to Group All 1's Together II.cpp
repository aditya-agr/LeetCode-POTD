class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size(), tot1=0;
        for(int i : nums)
            tot1 += i;

        int i=0, j=0, cur1=0;
        while(j<tot1)
            cur1 += nums[j++];
        j %= n;
        int res=INT_MAX;   
        for(i=0; i<n; i++){
            res = min(res, tot1-cur1);
            cur1 -= nums[i];
            cur1 += nums[j];
            j = (j+1)%n;
        }
        return res;
        
    }
};