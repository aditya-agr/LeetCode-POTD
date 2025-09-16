class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for(int x : nums){
            while(!res.empty() && __gcd(res.back(), x) > 1){
                x = x*1LL*res.back()/__gcd(res.back(), x);
                res.pop_back();
            }
            res.push_back(x);
        }
        return res;
    }
};