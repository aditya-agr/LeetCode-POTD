class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res, f(n);
        for(int x : nums){
            if(f[x] == 1)
                res.push_back(x);
            f[x]++;
        }
        return res;
    }
};