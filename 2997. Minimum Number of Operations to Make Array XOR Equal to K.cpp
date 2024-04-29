class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res=k;
        for(int i : nums)
            res ^= i;
        int cnt=0;
        // while(res){
        //     int rem = res%2;
        //     cnt += rem;
        //     res /= 2;
        // }
        cnt = __builtin_popcount(res);
        return cnt;
    }
};