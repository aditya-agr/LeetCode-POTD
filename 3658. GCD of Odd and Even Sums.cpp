class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumo=0, sume=0;
        for(int i=1; i<=2*n; i++){
            if(i%2)
                sumo += i;
            else
                sume += i;
        }
        return __gcd(sumo, sume);
    }
};