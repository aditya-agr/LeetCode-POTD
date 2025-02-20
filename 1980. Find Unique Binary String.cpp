class Solution {
public:
    string res;
    bool solve(string &curr, unordered_set<string> &st, int &n){
        if(curr.size() == n){
            if(st.count(curr) == 0){
                res = curr;
                return true;
            }
            return false;
        }
        curr.push_back('0');
        if(solve(curr, st, n)) return true;
        curr.pop_back();
        curr.push_back('1');
        if(solve(curr, st, n)) return true;
        curr.pop_back();
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        string curr = "";
        int n = nums.size();
        res = "";
        solve(curr, st, n);
        return res;
    }
};