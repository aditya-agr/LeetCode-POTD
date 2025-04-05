class Solution {
public:
    int solve(vector<int> &nums, int i, int Xor){
        if(i == nums.size())
            return Xor;
        int take = solve(nums, i+1, Xor^nums[i]);
        int notake = solve(nums, i+1, Xor);
        return take + notake;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};