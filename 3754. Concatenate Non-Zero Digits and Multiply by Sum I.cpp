class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0, x = 0, it = 1;
        while(n){
            int rem = n%10;
            n /= 10;
            if(rem == 0)
                continue;
            x += it*rem;
            sum += rem;
            it *= 10;
        }
        return sum*x;
    }
};