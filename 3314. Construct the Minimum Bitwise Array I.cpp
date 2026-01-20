class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        for(int i=0; i<n; i++){
            int val = nums[i];
            for(int j=1; j<val; j++){
                if((j|(j+1)) == val){
                    res[i] = j;
                    break;
                }
            }
        }
        return res;
    }
};