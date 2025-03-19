class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 1;
        int curr = 0;
        int n = nums.size();
        int i = 0, j = 0;
        while(j<n){
            while((curr&nums[j]) != 0){
                curr ^= nums[i];
                i++;
            }
            curr = (curr|nums[j]);
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};