class Solution {
public:
    string clearStars(string s) {
        unordered_map<char, vector<int>>mp;
        int i=0, n=s.size();
        for(auto &c : s){
            mp[c].push_back(i);
            i++;
        }
        for(auto &i : mp['*']){
            for(int j=0; j<26; j++){
                if(mp['a'+j].size()>0){
                    int idx = lower_bound(mp['a'+j].begin(), mp['a'+j].end(), i)-mp['a'+j].begin();
                    // cout<<idx;
                    if(idx-1>=0){
                        mp['a'+j].erase(mp['a'+j].begin()+idx-1);
                        break;
                    }
                }
            }
        }
        string r="";
        for(int i=0; i<n; i++){
            if(s[i]!='*'){
                char c=s[i];
                if(binary_search(mp[c].begin(), mp[c].end(), i))
                    r += c;
            }
        }
        return r;   
    }
};
