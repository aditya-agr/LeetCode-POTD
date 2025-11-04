class Solution {
public:
    int xsum(vector<int> &num, int x, int st, int ed){
        unordered_map<int, int> mp;
        for(int i=st; i<=ed; i++)
            mp[num[i]]++;
        vector<pair<int, int>> vec;
        for(auto it : mp)
            vec.push_back({it.second, it.first});
        sort(vec.rbegin(), vec.rend());
        int res = 0;
        for(int i=0; i<x && i<vec.size(); i++){
            res += vec[i].second*vec[i].first;
        }
        return res;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res(n-k+1);
        for(int i=0; i<n-k+1; i++){
            res[i] = xsum(nums, x, i, i+k-1);
        }
        return res;
    }
};