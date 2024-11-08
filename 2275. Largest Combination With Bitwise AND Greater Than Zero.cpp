class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0;
        for(int i=0; i<25; i++){
            int cnt = 0;
            for(int x : candidates){
                if(x&(1<<i))
                    cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};