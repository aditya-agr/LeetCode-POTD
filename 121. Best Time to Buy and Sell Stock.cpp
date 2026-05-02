class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int res = 0;
        for(int x : prices){
            res = max(res, x-mn);
            mn = min(mn, x);
        }
        return res;
    }
};