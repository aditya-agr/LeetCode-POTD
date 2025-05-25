class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int cnt = 0;
        int n = words.size();
        for(int i=0; i<n; i++){
            string s = words[i];
            swap(s[0], s[1]);
            if(mp.find(s) != mp.end() && mp[s] > 0){
                mp[s]--;
                cnt += 4;
                continue;
            }
            mp[words[i]]++;
        }
        for(auto it : mp){
            string s = it.first;
            if(it.second > 0 && s[0]==s[1]){
                cnt += 2;
                break;
            }
        }
        return cnt;
    }
};