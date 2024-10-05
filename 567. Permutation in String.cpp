class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;
        vector<int> f1(26);
        vector<int> f2(26);
        for(char c : s1)
            f1[c-'a']++;
        for(int i=0; i<n; i++)
            f2[s2[i]-'a']++;
        int i=0, j=n;
        while(j<m){
            if(f1 == f2)
                return true;
            f2[s2[j++]-'a']++;
            f2[s2[i++]-'a']--;
        }
        return f1 == f2;
    }
};