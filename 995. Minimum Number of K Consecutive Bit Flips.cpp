class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), res=0;
        vector<int> cnt(n+1);
        for(int i=0; i<n; i++){
            if(i>0) cnt[i] += cnt[i-1];
            if((!nums[i] && cnt[i]%2==0) || (nums[i] && cnt[i]%2)){
                cnt[i]++;
                res++;
                if(i+k > n)
                    return -1;
                cnt[i+k]--;
            }
        }
        return res;
    }
};