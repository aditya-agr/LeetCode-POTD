class Solution {
public:
    int k;
    int m;
    int t[1001][1001];
    int mod = 1e9+7;
    int solve(int i, int j, string &target, vector<vector<long long>> &freq){
        if(i == m) return 1;
        if(j == k) return 0;
        if(t[i][j] != -1) return t[i][j];
        int no_take = solve(i, j+1, target, freq)%mod;
        int take = (freq[target[i]-'a'][j] * solve(i+1, j+1, target, freq))%mod;
        return t[i][j] = (take + no_take)%mod;
    }
    int numWays(vector<string>& words, string target) {
        k = words[0].length();
        m = target.length();

        vector<vector<long long>> freq(26, vector<long long>(k));
        for(string s : words)
            for(int i=0; i<k; i++)
                freq[s[i]-'a'][i]++;

        memset(t, -1, sizeof(t));
        return solve(0, 0, target, freq);
    }
};