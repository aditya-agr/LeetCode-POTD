class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for(string &w : words){
            int tot=0;
            for(char c : w)
                tot += weights[c-'a'];
            int rem = tot%26;
            rem = (25-rem);
            res += char('a'+rem);
        }
        return res;
    }
};