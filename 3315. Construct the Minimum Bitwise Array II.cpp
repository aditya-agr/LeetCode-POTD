class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            int x = nums[i];
            if(x%2 == 0){
                res[i] = -1;
                continue;
            }
            int d=1, ans=INT_MAX;
            while(x&d){
                int cur = x^d;
                if((cur|(cur+1)) == x)
                    ans = min(ans, cur);
                d <<= 1;
            }
            res[i] = ans;
        }
        return res;
    }
};