class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.size();
        int n = rows;
        int m = len/n;
        string res = "";
        for(int x=0; x<m; x++){
            int i=0, j=x;
            while(i<n && j<m){
                res += encodedText[m*i+j];
                i++;
                j++;
            }
        }
        while(!res.empty() && res.back()==' ')
            res.pop_back();
        return res;
    }
};