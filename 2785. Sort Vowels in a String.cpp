class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    string sortVowels(string s) {
        vector<char> vow;
        for(char c : s)
            if(isVowel(c))
                vow.push_back(c);
        
        sort(vow.begin(), vow.end());
        
        int j=0;
        string res = "";
        for(char c : s)
            if(isVowel(c))
                res += vow[j++];
            else
                res += c;
        return res;
    }
};