class Solution {
public:
    string invert(string &s){
        int n = s.length();
        string res = "";
        for(char &c : s){
            if(c == '0')
                res += '1';
            else
                res += '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        if(k == 1)
            return '0';
        for(int i=0; i<n-1; i++){
            string inv = invert(s);
            s = s+"1"+inv;
        }
        cout<<s;
        return s[k-1];
    }
};