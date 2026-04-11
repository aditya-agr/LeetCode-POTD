class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int res = INT_MAX;
        for(auto &it : mp){
            vector<int> cur = it.second;
            if(cur.size() < 3)
                continue;
            for(int i=1; i<cur.size()-1; i++){
                res = min(res, 2*cur[i+1]-2*cur[i-1]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};