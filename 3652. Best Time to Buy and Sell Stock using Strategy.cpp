class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long tot = 0;
        int n = prices.size();
        for(int i=0; i<n; i++){
            tot += prices[i]*strategy[i];
        }
        long long res = tot;
        for(int i=0; i<k; i++){
            if(i<k/2)
                tot += -1*prices[i]*strategy[i];
            else{
                if(strategy[i] == 0)
                    tot += prices[i];
                if(strategy[i] == -1)
                    tot += 2*prices[i];
            }
        }
        res = max(res, tot);
        for(int i=k; i<n; i++){
            if(strategy[i] == 0)
                tot += prices[i];
            if(strategy[i] == -1)
                tot += 2*prices[i];
            tot += prices[i-k]*strategy[i-k];
            tot -= prices[i-k/2];
            res = max(res, tot);
        }
        return res;
    }
};