class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        int i=0, j=0;
        int n = nums.size();
        map<int, int> mp;
        while(j<n){
            mp[nums[j]]++;
            while(abs(mp.rbegin()->first - mp.begin()->first) > 2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            res += (j-i+1);
            j++;
        }
        return res;
    }
};