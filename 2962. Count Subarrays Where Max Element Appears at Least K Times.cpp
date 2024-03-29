class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=0, cnt=0;
        for(int i: nums)
            maxi = max(maxi, i);
        int i=0, j=0;
        long long n = nums.size();
        long long ans=0;
        while(j<n){
            if(nums[j]==maxi)
                cnt++;
            while(cnt>=k)
                if(nums[i++]==maxi)
                    cnt--;
            ans += (j-i+1);
            j++;
        }
        long long total = n*(n+1)/2;
        return total - ans;
    }
};