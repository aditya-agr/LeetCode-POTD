class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE = *max_element(nums.begin(), nums.end());
        int i=0;
        int j=0;
        int n = nums.size();
        long long res = 0;
        int cnt = 0;
        while(j<n){
            if(nums[j] == maxE)
                cnt++;
            while(cnt>=k){
                res += n-j;
                if(nums[i] == maxE)
                    cnt--;
                i++;
            }
            j++;
        }
        return res;
    }
};