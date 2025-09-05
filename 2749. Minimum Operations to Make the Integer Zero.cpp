class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=1; i<=60; i++){
            long long num = num1 - 1LL*i*num2;
            if(num < i)
                return -1;
            int x = __builtin_popcountll(num);
            if(i >= x)
                return i;
        }
        return -1;
    }
};