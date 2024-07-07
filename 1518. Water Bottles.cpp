class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        while(numBottles >= numExchange){
            int tmp = numBottles/numExchange;
            numBottles = tmp + numBottles%numExchange;
            res += tmp;
        }
        return res;
    }
};