class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i=0, j=0;
        unordered_map<int,int> mp;
        int d=0;
        int res = 0;
        while(j<n){
            if(mp[s[j]]==0)
                d++;
            mp[s[j]]++;
            while(d == 3){
                res += (n-j);
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    d--;
                i++;
            }
            j++;
        }
        return res;
    }
};