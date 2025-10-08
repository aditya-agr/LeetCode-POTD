class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res(n);
        for(int i=0; i<n; i++){
            long long sp = spells[i];
            long long rem = success/sp;
            rem += (success%sp > 0);
            int idx = lower_bound(potions.begin(), potions.end(), rem) - potions.begin();
            res[i] = m-idx;
        }
        return res;
    }
};