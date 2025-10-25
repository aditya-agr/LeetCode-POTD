class Solution {
public:

    int totalMoney(int n) {
        int div = n/7;
        int rem = n%7;
        int tot = 0;
        for(int i=0; i<div; i++){
            tot += 28 + 7*i;
        }
        tot += rem*(rem+1)/2 + div*rem;
        return tot;
    }
};