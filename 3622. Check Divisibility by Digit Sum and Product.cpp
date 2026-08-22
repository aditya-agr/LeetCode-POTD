class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int t = n;
        while(t){
            int rem = t%10;
            sum += rem;
            prod *= rem;
            t /= 10;
        }
        return n%(sum+prod) == 0;
    }
};