class Solution {
public:
    void solve(string &curr, string &res, int &cnt, int &k, int &n){
        if(curr.size() == n){
            cnt++;
            if(cnt == k)
                res = curr;
            return;
        }
        for(char c='a'; c<='c'; c++){
            if(!curr.empty() && curr.back() == c) continue;
            curr.push_back(c);
            solve(curr, res, cnt, k, n);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string res = "", curr = "";
        int cnt = 0;
        solve(curr, res, cnt, k, n);
        return res;
    }
};