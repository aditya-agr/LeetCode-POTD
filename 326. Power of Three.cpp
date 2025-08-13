class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 0)
            return false;
        long long it = 1;
        while(it <= n){
            if(it == n)
                return true;
            it *= 3;
        }
        return false;
    }
};