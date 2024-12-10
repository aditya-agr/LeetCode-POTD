class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> mp;
        int n = s.size();
        for(int i=0; i<n; i++){
            string curr = "";
            for(int j=i; j<n; j++){
                curr += s[j];
                if(s[i] == s[j])
                    mp[curr]++;
                else 
                    break;
            }
        }
        int res = -1;
        for(auto it : mp){
            int sz = it.first.size();
            if(it.second > 2 && sz > res)
                res = sz;
        }
        return res;
    }
};