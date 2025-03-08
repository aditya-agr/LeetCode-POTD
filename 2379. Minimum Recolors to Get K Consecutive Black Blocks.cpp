class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int cnt = 0;
        for(int i=0; i<k; i++){
            if(blocks[i] == 'W')
                cnt++;
        }
        int res = cnt;
        for(int i=k; i<n; i++){
            cnt += (blocks[i] == 'W') ? 1 : 0;
            cnt -= (blocks[i-k] == 'W') ? 1 : 0;
            res = min(res, cnt);
        }
        return res;
    }
};