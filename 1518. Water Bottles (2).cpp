
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        while(numBottles >= numExchange){
            int newBottle = (numBottles/numExchange);
            int rem = (numBottles%numExchange);
            res += newBottle;
            numBottles = newBottle + rem;
        }
        return res;
    }
};