class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for(int x : nums){
            int cur = 0;
            while(x){
                cur += x%10;
                x /= 10;
            }
            res = min(res, cur);
        }
        return res;
    }
};