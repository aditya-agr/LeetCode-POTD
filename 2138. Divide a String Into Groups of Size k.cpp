class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> res;
        for(int i=0; i<n; i+=k){
            string cur = s.substr(i, k);
            res.push_back(cur);
        }
        int len = res.size();
        if(res[len-1].size() != k){
            res[len-1] += string(k-res[len-1].size(), fill);
        }
        return res;
    }
};