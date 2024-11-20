class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> cnt(3,0);
        for(char ch : s)
            cnt[ch-'a']++;

        if(cnt[0]<k || cnt[1]<k || cnt[2]<k)
            return -1;

        int i=0, j=0;
        int n = s.length(), notDel = 0;
        while(j<n){
            cnt[s[j]-'a']--;
            while(i<=j && (cnt[0]<k || cnt[1]<k || cnt[2]<k)){
                cnt[s[i]-'a']++;
                i++;
            }
            notDel = max(notDel, j-i+1);
            j++;
        }
        return n - notDel;
    }
};