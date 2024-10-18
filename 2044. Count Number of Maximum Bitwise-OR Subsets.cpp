class Solution {
public
    int solve(int i, int curr, int mx, vectorint&nums){
        if(i == nums.size())
            return curr == mx;
        return solve(i+1, curr, mx, nums) +
            solve(i+1, currnums[i], mx, nums);
    }
    int countMaxOrSubsets(vectorint& nums) {
        int mx=0;
        for(int x  nums)
            mx = x;
        return solve(0, 0, mx, nums);
    }
};