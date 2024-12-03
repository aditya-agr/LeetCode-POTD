class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = s.substr(0, spaces[0]);
        int n = spaces.size();
        for(int i=1; i<n; i++){
            string str = s.substr(spaces[i-1], spaces[i]-spaces[i-1]);
            res += " ";
            res += str;
        }
        res += " ";
        res += s.substr(spaces[n-1]);
        return res;
    }
};