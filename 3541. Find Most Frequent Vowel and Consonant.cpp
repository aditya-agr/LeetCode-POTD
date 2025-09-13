class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u'; 
    }
    int maxFreqSum(string s) {
        vector<int> f(26);
        for(char c : s)
            f[c-'a']++;
        int vow = 0, con = 0;
        for(int i=0; i<26; i++){
            if(isVowel('a'+i))
                vow = max(vow, f[i]);
            else
                con = max(con, f[i]);
        }
        return vow+con;
    }
};