class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>mp;
        for(char c : s)
            mp[c]++;
        int cnt=0, mx=0;
        for(auto &i : mp){
            if(i.second%2){
                cnt += i.second-1;
                mx=1;
            }
            else
                cnt += i.second;
        }
        return cnt+mx;
    }
};