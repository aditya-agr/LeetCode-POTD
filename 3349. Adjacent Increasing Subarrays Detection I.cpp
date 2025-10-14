class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1 && n>1)
            return true;
        if(2*k > n)
            return false;
        for(int i=0; i<n-k; i++){
            int cnt = 1;
            for(int j=i+1; j<n; j++){
                if(nums[j] > nums[j-1])
                    cnt++;
                else
                    break;
                if(cnt == k)
                    j++, cnt++;
                if(cnt == 2*k)
                    return true;
            }
        }
        return false;
    }
};