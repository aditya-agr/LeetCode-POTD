class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> vow(5);
        unordered_map<string, int> mp;
        mp["00000"] = -1;
        int ans=0;
        int n=s.length();
        for(int i=0; i<n; i++){
            if(s[i]=='a') vow[0] = (vow[0]+1)%2; 
            if(s[i]=='e') vow[1] = (vow[1]+1)%2; 
            if(s[i]=='i') vow[2] = (vow[2]+1)%2; 
            if(s[i]=='o') vow[3] = (vow[3]+1)%2; 
            if(s[i]=='u') vow[4] = (vow[4]+1)%2; 

            string curr="";
            for(int it : vow)
                curr += to_string(it);
            
            if(mp.count(curr))
                ans = max(ans, i-mp[curr]);
            else
                mp[curr] = i;
        }
        return ans;
    }
};