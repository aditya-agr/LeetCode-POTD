class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mx = 0;
        for(int &x : costs)
            mx = max(mx, x);

        vector<int> freq(mx+1);
        for(int &x : costs) 
            freq[x]++;
        
        int res = 0;
        for(int i=1; i<=mx; i++){
            if(freq[i]>0){
                int mn = min(coins/i, freq[i]);
                res += mn;
                coins -= mn*i;
            }
        }
        return res;
    }
};