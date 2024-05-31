class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0;
        for(auto &i : nums)
            xr ^= i;
        int idx=0, x1=0, x2=0;
        for(int i=0; i<=32; i++){
            if(xr&(1<<i)){
                idx = i;
                break;
            }
        }
        for(auto &i : nums){
            if(i&(1<<idx))
                x1 ^= i;
            else
                x2 ^= i;
        }

        return {x1, x2};
    }
};