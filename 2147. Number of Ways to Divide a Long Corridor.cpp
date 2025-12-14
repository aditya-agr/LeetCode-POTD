class Solution {
public:
    int mod = 1e9+7;
    int numberOfWays(string corridor) {
        int cnt = 0;
        for(char c : corridor)
            if(c == 'S')
                cnt++;

        if(cnt%2 == 1 || cnt == 0) return 0;
        if(cnt == 2) return 1;
        
        int n = corridor.length();
        int cntP = 0;
        int cntS = 0;
        long long res = 1;
        for(int i=0; i<n; i++){
            if(corridor[i] == 'S'){
                cntS++;
                if(cntS>2 && cntS%2 == 1){
                    res = (res%mod * (cntP+1)%mod)%mod;
                    cntP = 0;
                }
            }
            else{
                if(cntS>0 && cntS%2 == 0)
                    cntP++;
            }
        }
        return res;
    }
};