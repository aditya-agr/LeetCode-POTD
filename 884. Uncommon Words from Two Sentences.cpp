class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string word;
        stringstream ss1(s1);
        stringstream ss2(s2);
        unordered_map<string, int> mp;
        while(ss1>>word)
            mp[word]++;
        while(ss2>>word)
            mp[word]++;
        vector<string> res;
        for(auto &s : mp){
            if(s.second==1)
                res.push_back(s.first);
        }
        return res;
    }
};