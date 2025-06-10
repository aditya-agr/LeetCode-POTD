class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26);
        for(char c : s)
            freq[c-'a']++;
        int a1 = 0, a2 = INT_MAX;
        for(int i=0; i<26; i++){
            if(freq[i]){
                if(freq[i]%2)
                    a1 = max(a1, freq[i]);
                else
                    a2 = min(a2, freq[i]);
            }
        }
        return a1-a2;
    }
};