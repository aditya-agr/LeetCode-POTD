class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int cnt = n;
        vector<int> used(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(fruits[i] <= baskets[j]){
                    baskets[j] = 0;
                    cnt--;
                    break;
                }
            }
        }
        return cnt;
    }
};