class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int i=0, j=0;
        int n=nums.size(), ans=0;
        long long prod=1;
        while(j<n){
            prod*=nums[j];
            while(prod>=k)
                prod /= nums[i++];
            ans += 1+(j-i);
            j++;
        }
        return ans;
    }
};