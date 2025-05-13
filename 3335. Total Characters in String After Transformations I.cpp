class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> mp1(26);
        int mod = 1e9+7;
        for(char c : s)
            mp1[c-'a']++;
        for(int i=0; i<t; i++){
            vector<int> mp2(26);
            for(int i=0; i<26; i++){
                char c = i+'a';
                int freq = mp1[i];
                if(c!='z')
                    mp2[i+1] = (mp2[i+1]%mod + freq%mod)%mod;
                else{
                    mp2[0] = (mp2[0]%mod + freq%mod)%mod;
                    mp2[1] = (mp2[1]%mod + freq%mod)%mod;
                }
            }
            mp1 = mp2;
        }
        long long tot = 0;
        for(int i=0; i<26; i++)
            tot = (tot%mod + mp1[i]%mod)%mod;
        return tot;
    }
};