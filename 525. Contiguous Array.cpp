class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum=0;
        mp[0]=-1;
        int n=nums.size(), maxi=0;
        for(int i=0; i<n; i++){
            sum += (nums[i]==0)? -1: 1;
            if(mp.find(sum) == mp.end())
                mp[sum]=i;
            else
                maxi = max(i-mp[sum], maxi);
        }
        return maxi;
    }
};