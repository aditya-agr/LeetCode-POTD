class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> dp(n);
        int i=0, j=0;
        int dist=0, cnt=0;
        int res = 0;
        while(j<n){
            if(dp[fruits[j]] == 0)
                dist++;
            dp[fruits[j]]++;
            cnt++;
            while(dist > 2){
                dp[fruits[i]]--;
                cnt--;
                if(dp[fruits[i]]== 0)
                    dist--;
                i++;
            }
            res = max(res, cnt);
            j++;
        }
        return res;
    }
};