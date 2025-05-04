class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        int n = dominoes.size();
        int cnt = 0;
        for(vector<int> v : dominoes){
            pair<int,int> x = {v[0], v[1]};
            if(x.first > x.second)
                swap(x.first, x.second);
            if(mp.find(x) != mp.end())
                cnt += mp[x];
            mp[x]++;
        }
        return cnt;
    }
};