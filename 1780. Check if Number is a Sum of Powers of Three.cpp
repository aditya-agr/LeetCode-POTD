class Solution {
public:
    bool solve(int n, int p){
        if(n == 0)
            return true;
        if(pow(3, p) > n)
            return false;
        int take = solve(n-pow(3, p), p+1);
        int notake = solve(n, p+1);
        return take|notake;
    }
    bool checkPowersOfThree(int n) {
        // while(n>0){
        //     if(n%3 == 2)
        //         return false;
        //     n = n/3;
        // }
        // return true;

        // int p=0;
        // while(pow(3, p) < n){
        //     p++;
        // }
        // while(n>0){
        //     if(n>=pow(3,p))
        //         n -= pow(3, p);
        //     if(n>=pow(3,p))
        //         return false;
        //     p--;
        // }
        // return true;

        return solve(n, 0);
    }
};