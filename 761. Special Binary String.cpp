class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s == "")
            return s;
        int n = s.length();
        int sum = 0;
        int start = 0;
        vector<string> res;
        for(int i=0; i<n; i++){
            sum += (s[i]=='0') ? -1 : 1;
            if(sum == 0){
                string sub = s.substr(start+1, i-start-1);
                res.push_back("1" + makeLargestSpecial(sub) + "0");
                start = i+1;
            }
        }
        sort(res.rbegin(), res.rend());
        string ans="";
        for(string &t : res)
            ans += t;
        return ans;
    }
};