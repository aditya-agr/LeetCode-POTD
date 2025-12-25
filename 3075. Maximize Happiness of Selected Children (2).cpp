class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(false),
        cin.tie(0),
        cout.tie(0);
        long long res = 0;
        sort(happiness.rbegin(), happiness.rend());
        for(int i=0; i<k; i++){
            res += max(happiness[i]-i, 0);
            if(happiness[i]-i <= 0)
                break;
        }
        return res;
    }
};