class Solution {
    public:
        int solve(int j, int k, vector<int>&arr, unordered_map<int, int>&mp, vector<vector<int>> &dp){
            if(dp[j][k] != -1)
                return dp[j][k];
            int temp = arr[k]-arr[j];
            if(mp.count(temp) && mp[temp]<j){
                int i = mp[temp];
                return dp[j][k] = solve(i, j, arr, mp, dp)+1;
            }
            return dp[j][k] = 2;
        }
        int lenLongestFibSubseq(vector<int>& arr) {
            int n = arr.size();
            vector<vector<int>> dp(n, vector<int>(n, -1));
            unordered_map<int, int> mp;
            for(int i=0; i<n; i++){
                mp[arr[i]] = i;
            }
            int res = 0;
            for(int j=1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    int len = solve(j, k, arr, mp, dp);
                    if(len>=3)
                        res = max(res, len);
                }
            }
            return res;
        }
    };