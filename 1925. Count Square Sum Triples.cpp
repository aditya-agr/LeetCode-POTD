class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int k2 = i*i + j*j;
                int k = sqrt(k2);
                if(k*k == k2 && k<=n)
                    cnt++;
            }
        }
        return cnt;
    }
};