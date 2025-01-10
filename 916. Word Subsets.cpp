class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> idx(26);
        for(string s : words2){
            vector<int> curr(26);
            for(char c : s)
                curr[c-'a']++;
            for(int i=0; i<26; i++)
                idx[i] = max(idx[i], curr[i]);
        }
        vector<string> res;
        for(string s : words1){
            vector<int> curr(26);
            for(char c : s)
                curr[c-'a']++;
            bool flag = true;
            for(int i=0; i<26; i++)
                if(curr[i] < idx[i])
                    flag =  false;
            if(flag)
                res.push_back(s);
        }
        return res;
    }
};