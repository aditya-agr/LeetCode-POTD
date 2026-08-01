class Solution {
public:
    bool solve(int i, int j, int p1, int p2, bool ch, vector<int> &nums){
        if(i>j)
            return p1 >= p2;
        bool a, b;
        if(ch){
            a = solve(i+1, j, p1+nums[i], p2, false, nums);
            b = solve(i, j-1, p1+nums[j], p2, false, nums);
            return a | b;
        }
        else{
            a = solve(i+1, j, p1, p2+nums[i], true, nums);
            b = solve(i, j-1, p1, p2+nums[j], true, nums);
            return a & b;
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1, p1 = 0, p2 = 0;
        bool a = solve(i+1, j, p1+nums[i], p2, false, nums);
        bool b = solve(i, j-1, p1+nums[j], p2, false, nums);
        return a | b;
    }
};