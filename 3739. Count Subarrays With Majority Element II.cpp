class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<long long, int> mp;
        long long cumSum=0, left=0;
        mp[0] = 1;
        long long res = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                left += mp[cumSum];
                cumSum += 1;
            }
            else{
                cumSum -= 1;
                left -= mp[cumSum];
            }
            mp[cumSum] += 1;
            res += left;
        }
        return res;
    }
};