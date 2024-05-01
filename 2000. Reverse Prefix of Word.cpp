class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx=-1, n=word.size();
        for(int i=0; i<n; i++){
            if (word[i] == ch){
                idx = i;
                break;
            }
        }
        if(idx==-1) return word;
        string res="";
        for(int i=idx; i>=0; i--)
            res+=word[i];
        for(int i=idx+1; i<n; i++)
            res+=word[i];
        return res;
    }
};