class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> a(n+1);
        int i2=1, i3=1, i5=1;
        a[1] = 1;
        int i=2;
        while(i<=n){
            int u2 = a[i2]*2;
            int u3 = a[i3]*3;
            int u5 = a[i5]*5;
            a[i] = min(u2, min(u3, u5));
            if(a[i]==u2)
                i2++;
            if(a[i]==u3)
                i3++;
            if(a[i]==u5)
                i5++;
            i++;
        }
        return a[n];
    }
};