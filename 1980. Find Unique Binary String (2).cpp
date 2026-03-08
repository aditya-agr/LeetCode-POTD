class Solution {
public:
    string solve(int n, string &s, unordered_set<string> st){
        if(n == 0){
            if(!st.count(s))
                return s;
            else
                return "";
        }
        s.push_back('0');
        string left = solve(n-1, s, st);
        s.pop_back();
        if(left != "")
            return left;
        s.push_back('1');
        string right = solve(n-1, s, st);
        s.pop_back();
        if(right != "")
            return right;
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        string s = "";
        int n = nums[0].length();
        return solve(n, s, st);
    }
};