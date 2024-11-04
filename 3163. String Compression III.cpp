class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int cnt = 0;
        int n = word.size();
        for(int i=0; i<n; i++){
            cnt++;
            if(word[i]!=word[i+1] || cnt==9){
                comp += to_string(cnt) + word[i];
                cnt = 0;
            }
        }
        return comp;
    }
};