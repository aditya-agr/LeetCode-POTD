class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> f(101, 0);
        int cnt=0, mx=0;
        for(int x : nums){
            f[x]++;
            if(f[x] > mx){
                mx = f[x];
                cnt = 1;
            }
            else if(f[x] == mx)
                cnt++;
        }
        return cnt*mx;
    }
};