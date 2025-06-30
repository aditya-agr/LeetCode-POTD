class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int &x: nums)
            mp[x]++;
        int res = 0;
        for(int &x: nums){
            if(mp.count(x+1))
                res = max(res, mp[x]+mp[x+1]);
        }
        return res;
    }
};