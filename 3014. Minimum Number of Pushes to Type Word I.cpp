class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26);
        for(char c : word)
            mp[c-'a']++;
        sort(mp.rbegin(), mp.rend());
        int res = 0, it = 0;
        for(int i=0; i<26; i++){
            if(i%8 == 0)
                it++;
            res += mp[i]*it;
        }
        return res;
    }
};