class Solution {
public:
    unordered_map<string, bool> dp;
    bool solve(string curr, int idx, unordered_map<string, vector<char>> &mp, string above){
        if(curr.size() == 1)
            return true;
        string key = curr+"#"+to_string(idx)+"#"+above;
        if(dp.count(key))
            return dp[key];
        if(idx == curr.size()-1)
            return dp[key] = solve(above, 0, mp, "");
        string s = curr.substr(idx, 2);
        if(!mp.count(s))
            return dp[key] = false;
        for(char &c : mp[s]){
            above.push_back(c);
            if(solve(curr, idx+1, mp, above))
                return dp[key] = true;
            above.pop_back();
        }
        return dp[key] = false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for(string &s : allowed){
            string k = s.substr(0,2);
            mp[k].push_back(s[2]);
        }
        return solve(bottom, 0, mp, "");
    }
};