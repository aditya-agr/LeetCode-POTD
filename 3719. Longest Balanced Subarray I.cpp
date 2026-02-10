class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int distO, distE;
        int res = 0;
        for(int i=0; i<n; i++){
            mp.clear();
            distO=0, distE=0;
            for(int j=i; j<n; j++){
                mp[nums[j]]++;
                if(mp[nums[j]] == 1){
                    if(nums[j]%2)
                        distO++;
                    else
                        distE++;
                }
                if(distO == distE)
                    res = max(res, j-i+1);
            }
        }
        return res;
    }
};