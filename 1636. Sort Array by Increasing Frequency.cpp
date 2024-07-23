class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int ,int> mp;
        for(auto &i : nums)
            mp[i]++;
        vector<pair<int, int>> vec;
        for(auto &it : mp)
            vec.push_back({it.second, it.first});
        
        auto comp = [&](pair<int, int> a, pair<int, int> b){
            if(a.first<b.first)
                return true;
            else if(a.first>b.first)
                return false;
            return a.second>b.second;
        };

        sort(vec.begin(), vec.end(), comp);
        int i=0;
        for(auto &x : vec)
            while(x.first--)
                nums[i++] = x.second;
        return nums;
    }
};