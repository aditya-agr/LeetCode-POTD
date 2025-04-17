class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mpidx;
        int n = nums.size();
        for(int i=0; i<n; i++)
            mpidx[nums[i]].push_back(i);
        
        unordered_set<int> div;
        for(int i=1; i*i<=k; i++){
            if(k%i == 0){
                div.insert(i);
                div.insert(k/i);
            }
        }
        int res = 0;
        for(auto &it : mpidx){
            vector<int> curr = it.second;
            unordered_map<int, int> mp;
            for(int i : curr){
                int GCD = gcd(i, k);
                int j = k/GCD;
                res += mp[j];

                for(int f : div){
                    if(i%f == 0)
                        mp[f]++;
                }
            }
        }
        return res;
    }
};