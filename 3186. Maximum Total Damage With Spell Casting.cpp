class Solution {
public:
    long long solve(vector<int> &power, int i, vector<long long> &dp, unordered_map<int, int> &mp){
        int n = power.size();
        if(i == n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int j=i+1;
        while(j<n && power[j] <= power[i]+2)
            j++;
        long long po = power[i], cnt = mp[power[i]];
        long long take = po*cnt + solve(power, j, dp, mp);
        long long notake = solve(power, i+1, dp, mp);
        return dp[i] = max(take, notake);
    }
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        unordered_map<int, int> mp;
        for(int x : power)
            mp[x]++;
        set<int> st(power.begin(), power.end());
        vector<int> vec(st.begin(), st.end());
        vector<long long> dp(n, -1);
        long long res = solve(vec, 0, dp, mp);
        return res;
    }
};