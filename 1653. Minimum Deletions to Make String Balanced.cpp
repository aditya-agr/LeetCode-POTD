class Solution {
public:
    int minimumDeletions(string s) {
        int cnta=0, cntb=0, res=INT_MAX;
        for(char c : s){
            if(c=='a')
                cnta++;
        }
        for(char c : s){
            if(c=='a')
                cnta--;
            res = min(res, cnta+cntb);
            if(c=='b')
                cntb++;

        }
        return res;
    }
}; 