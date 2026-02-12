class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int res = 0;
        for(int i=0; i<n; i++){
            unordered_map<char, int> mp;
            for(int j=i; j<n; j++){
                mp[s[j]]++;
                bool flag = true;
                int cnt = mp[s[j]];
                for(auto &it : mp){
                    if(cnt != it.second)
                        flag = false;
                }            
                if(flag)
                    res = max(res, j-i+1);
            }
        }
        return res;
    }
};