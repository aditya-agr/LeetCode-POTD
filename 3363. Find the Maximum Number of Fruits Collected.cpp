class Solution {
public:
    int solve(vector<vector<int>> &fruits){
        int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp = fruits;
        if(n==2)
            return dp[0][n-1];
        if(n==3)
            return dp[0][n-1] + dp[1][n-1];
        for(int i=n-2; i>1; i--){
            for(int j=i+1; j<n; j++){
                int x = i-1;
                for(int k=j-1; k<=j+1; k++)
                    if(k>x && x>=0 && k>=0 && x<n && k<n)
                        dp[x][k] = max(dp[x][k], fruits[x][k]+dp[i][j]);
            }
        }
        return fruits[0][n-1] + max(dp[1][n-1], dp[1][n-2]);
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int ans = 0;
        for(int i=0; i<n; i++)
            ans += fruits[i][i];
        
        ans += solve(fruits);
        cout<<ans;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                swap(fruits[i][j], fruits[j][i]);
        
        ans += solve(fruits);
        return ans;
    }
};