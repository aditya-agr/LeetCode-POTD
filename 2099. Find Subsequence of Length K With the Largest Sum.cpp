class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp = nums;
        sort(temp.rbegin(), temp.rend());
        unordered_map<int, int> mp;
        for(int i=0; i<k; i++)
            mp[temp[i]]++;
        vector<int> res;
        for(int x : nums){
            if(mp[x]){
                res.push_back(x);
                mp[x]--;
            }
        }
        return res;
    }
};