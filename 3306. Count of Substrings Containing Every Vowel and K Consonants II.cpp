class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a') || (ch=='e') || (ch=='i') || (ch=='o') || (ch=='u');
    }
    long long countOfSubstrings(string word, int k) {
        unordered_map<int,int> mp;
        int n = word.length();
        vector<int> nextCons(n);
        int lastCons = n;
        for(int i=n-1; i>=0; i--){
            nextCons[i] = lastCons;
            if(!isVowel(word[i]))
                lastCons = i;
        }
        int i=0, j=0;
        long long count = 0;
        int cons = 0;
        while(j<n){
            char ch = word[j];
            if(isVowel(ch))
                mp[ch]++;
            else
                cons++;
            
            while(cons>k){
                char c = word[i];
                if(isVowel(c)){
                    mp[c]--;
                    if(mp[c] == 0)
                        mp.erase(c);
                }
                else
                    cons--;
                i++;
            }

            while(cons == k && mp.size() == 5){
                count += nextCons[j] - j;
                char c = word[i];
                if(isVowel(c)){
                    mp[c]--;
                    if(mp[c] == 0)
                        mp.erase(c);
                }
                else
                    cons--;
                i++;
            }
            j++;
        }
        return count;
    }
};