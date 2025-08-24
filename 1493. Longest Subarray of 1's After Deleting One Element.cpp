class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt=0, res=0, prev=0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1)
                cnt++;
            else{
                prev = cnt;
                cnt = 0;
            }
            res = max(res, prev+cnt);
        }
        return (res==n) ? n-1 : res;
    }
};