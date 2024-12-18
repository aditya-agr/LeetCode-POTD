class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            res[i] = prices[i];
            int j = i+1;
            while(j<n && prices[j]>prices[i])
                j++;
            if(j<n) res[i] -= prices[j];
        }
        return res;
    }
};