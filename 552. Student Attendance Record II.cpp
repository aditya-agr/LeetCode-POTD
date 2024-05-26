class Solution {
public:
    int checkRecord(int n) {
        int t[n+1][2][3];
        int m = 1e9+7;
        for(int a=0; a<2; a++)
            for(int l=0; l<3; l++)
                t[0][a][l] = 1;
        
        for(int i=1; i<=n; i++){
            for(int a=0; a<2; a++){
                for(int l=0; l<3; l++){
                    long long res = t[i-1][a][0];
                    res += (a+1<2) ? t[i-1][a+1][0] : 0;
                    res += (l+1<3) ? t[i-1][a][l+1] : 0;
                    t[i][a][l] = res%m;
                }
            }
        }
        return t[n][0][0];
    }
};