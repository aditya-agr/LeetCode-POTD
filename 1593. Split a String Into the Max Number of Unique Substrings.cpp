class Solution {
public:
    void solve(int i, int curr, int &mx, unordered_set<string> &st, string &s){
        if(curr+s.length()-i <= mx)
            return;
        if(i >= s.length()){
            mx = max(mx, curr);
            return;
        }
        for(int j=i; j<s.length(); j++){
            string str = s.substr(i, j-i+1);
            if(st.find(str) == st.end()){
                st.insert(str);
                solve(j+1, curr+1, mx, st, s);
                st.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int ans=0, curr=0;
        solve(0, curr, ans, st, s);
        return ans;
    }
};