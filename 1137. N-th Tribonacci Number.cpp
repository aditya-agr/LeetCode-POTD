class Solution {
public:
    int tribonacci(int n) {
        int a=0, b=1, c=1, d=1;
        if (n==0) return 0;
        for(int i=0; i<=n-3; i++){
            d = a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return d;
    }
};