class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int res = INT_MAX;
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        for(auto it : mp){
            vector<int> cur = it.second;
            if(cur.size() > 2){
                for(int i=0; i<=cur.size()-3; i++)
                    res = min(res, cur[i+2]-cur[i+1]+cur[i+2]-cur[i]+cur[i+1]-cur[i]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};ss