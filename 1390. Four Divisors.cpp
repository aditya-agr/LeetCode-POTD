class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for(int x : nums){
            int sq = sqrt(x);
            unordered_set<int> div;
            for(int i=1; i<=sq; i++){
                if(x%i == 0){
                    div.insert(i);
                    div.insert(x/i);
                }
            }
            if(div.size() == 4){
                for(int x : div)
                    res += x;
            }
        }
        return res;
    }
};