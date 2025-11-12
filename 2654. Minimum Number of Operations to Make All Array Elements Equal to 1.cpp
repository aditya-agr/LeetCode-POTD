class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        for(int x : nums)
            if(x == 1) cnt1++;
        if(cnt1)
            return n-cnt1;
        
        int mn = INT_MAX;
        for(int i=0; i<n; i++){
            int g = nums[i];
            for(int j=i+1; j<n; j++){
                g = __gcd(g, nums[j]);
                if(g == 1){
                    mn = min(mn, j-i+1);
                }
            }
        }
        return mn == INT_MAX ? -1 : n+mn-2;
    }
};