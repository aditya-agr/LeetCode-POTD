class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> cnt, cnt2, same;
        int n = tops.size();
        for(int x : tops)  
            cnt[x]++;
        for(int i=0; i<n; i++){
            if(tops[i]==bottoms[i]) 
                same[tops[i]]++;
            cnt2[bottoms[i]]++;
        }
        int res = INT_MAX;
        for(int i=1; i<=6; i++){
            if(cnt[i]+cnt2[i]-same[i] >= n){
                int mx = max(cnt[i], cnt2[i]);
                res = min(res, n-mx);
            }
        }
        return (res == INT_MAX) ? -1 : res;
    }
};