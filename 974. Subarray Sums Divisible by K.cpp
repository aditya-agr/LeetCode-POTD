class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]=1;
        int sum=0, res=0, m;
        int n=nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
            m = sum%k;
            if(sum%k<0)
                m += k;
            if(mp.count(m))
                res += mp[m];
            mp[m]++;
        }
        return res;
    }
};