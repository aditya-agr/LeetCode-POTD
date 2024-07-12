class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int cnta=0;      
        int cntb=0;
        int mn = min(x, y);
        int res=0;
        for(char &ch : s){
            if(ch == 'a'){
                if(y>x && cntb>0){
                    res += y;
                    cntb--;
                }
                else
                    cnta++;
            }
            else if(ch == 'b'){
                if(x>y && cnta>0){
                    res += x;
                    cnta--;
                }
                else
                    cntb++;
            }
            else{
                res += min(cnta, cntb)*mn;
                cnta=0;
                cntb=0;
            }
        }
        res += min(cnta, cntb)*mn;
        return res;
    }
};