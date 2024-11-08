class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> res;
        int XOR = 0;
        for(int x : nums)
            XOR ^= x;
        
        int mask = (1<<maximumBit) - 1;
        int n = nums.size();
        for(int i=n-1; i>=0; i--){
            int k = XOR ^ mask;
            res.push_back(k);
            XOR ^= nums[i];
        }
        return res;
    }
};