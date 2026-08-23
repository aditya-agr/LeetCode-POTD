class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int cntl = 0, suml = 0;
        for(int i=0; i<n/2; i++){
            if(num[i] == '?')
                cntl++;
            else
                suml += (num[i]-'0');
        }
        int cntr = 0, sumr = 0;
        for(int i=n/2; i<n; i++){
            if(num[i] == '?')
                cntr++;
            else
                sumr += (num[i]-'0');
        }
        if((cntl+cntr)==0)
            return suml != sumr;
        if((cntl+cntr)%2)
            return true;
        
        if(cntl == cntr)
            return suml != sumr;
        return 2*(suml - sumr) != 9*(cntr-cntl);
    }
};