class Solution {
public
    int numSubarraysWithSum(vectorint& nums, int goal) {
        int cnt = 0, sum=0;
        int n = nums.size();
        unordered_mapint, int mp;
        mp[0]=1;
        for(int i=0; in; i++){
            sum+=nums[i];
            if(mp.find(sum-goal) != mp.end())
                cnt += mp[sum-goal];
            mp[sum]++;
        }
        return cnt;
    }
};