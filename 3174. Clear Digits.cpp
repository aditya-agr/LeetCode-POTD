class Solution {
public:
    string clearDigits(string s) {
        string res = "";
        int n = s.length(), c = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i]>='0' && s[i]<='9')
                c++;
            else{
                if(c>0)
                    c--;
                else
                    res = s[i]+res;
            }
        }
        return res;
    }
};