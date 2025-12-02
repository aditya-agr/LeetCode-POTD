class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp;
        for(vector<int> &p : points)
            mp[p[1]]++;
        
        long long count = 0, mod = 1e9+7;
        vector<int> vec;
        long long res = 0;
        for(auto it : mp){
            long long n = it.second;
            long long temp = n%mod*(n-1)%mod/2;
            temp %= mod;
            res += count%mod * temp%mod;
            res %= mod;
            count += temp;
        }
        return res;
    }
};