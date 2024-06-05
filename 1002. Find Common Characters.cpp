class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> idx(26,1e9);
        for(auto &word : words){
            vector<int> freq(26,0);
            for(auto &c : word)
                freq[c-'a']++;
            for(int i=0; i<26; i++)
                idx[i] = min(idx[i], freq[i]);
        }
        vector<string> res;
        for(int i=0; i<26; i++){
            while(idx[i]){
                string c = string(1, ('a'+i));
                res.push_back(c);
                idx[i]--;
            }
        }
        return res;
    }
};