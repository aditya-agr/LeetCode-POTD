class Solution {
public:
    int solve(vector<string>& words, vector<int>& score, int i, vector<int> fr){
        if(i==words.size())
            return 0;
        int take=0, notake=0;
        vector<int> tf = fr;
        int scor=0, flag=0;
        for(auto c : words[i]){
            tf[c-'a']--;
            scor += score[c-'a'];
            if(tf[c-'a']<0){
                flag=1;
                break;
            }
        }
        if(flag==0)
            take = scor + solve(words, score, i+1, tf);
        notake = solve(words, score, i+1, fr);
        return max(take, notake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> fr(26,0);
        for(auto ch: letters)
            fr[ch-'a']++;
        return solve(words, score, 0, fr);
    }
};