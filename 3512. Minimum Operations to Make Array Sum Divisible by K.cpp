class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int tot = 0;
        for(int x : nums){
            tot += x;
        }
        return tot%k;
    }
};