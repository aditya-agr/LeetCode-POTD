class Solution {
public:
    vector<string> solve(string &s, unordered_set<string> &st, unordered_map<string, vector<string>> &mp){
        if(s.empty())
            return {""};
        if(mp.count(s))
            return mp[s];
        vector<string> res;
        for(int i=1; i<=s.size(); i++){
            string tmp = s.substr(0,i);
            if(st.count(tmp)){
                string rem = s.substr(i);
                vector<string> vec = solve(rem, st, mp);
                for(auto &w : vec){
                    string nw = tmp + (w.empty() ? "" : " ") + w;
                    res.push_back(nw);
                }
            }
        }
        return mp[s]=res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        unordered_map<string, vector<string>> mp;
        for(auto &w : wordDict)
            st.insert(w);
        return solve(s, st, mp);
    }
};