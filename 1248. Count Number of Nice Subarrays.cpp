class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int cnt=0, res=0;
        mp[cnt]++;
        for(auto &i : nums){
            if(i%2)
                cnt++;
            res += mp[cnt-k];
            mp[cnt]++;
        }
        return res;
    }
};