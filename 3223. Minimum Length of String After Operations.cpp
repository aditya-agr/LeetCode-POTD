class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        for(auto &c : s)
            mp[c]++;
        int ans=0;
        for(auto &i : mp){
            int l = i.second;
            while(l>=3){
                l-=2;
            }
            ans += l;
        }
        return ans;
    }
};