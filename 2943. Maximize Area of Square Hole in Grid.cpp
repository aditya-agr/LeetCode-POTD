class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int h = hBars.size();
        int cnt=1, mxX=2; 
        for(int i=1; i<h; i++){
            if(hBars[i]-1 == hBars[i-1])
                cnt++;
            else
                cnt = 1;
            mxX = max(mxX, cnt+1);
        }
        int v = vBars.size();
        cnt=1; 
        int mxY=2; 
        for(int i=1; i<v; i++){
            if(vBars[i]-1 == vBars[i-1])
                cnt++;
            else
                cnt = 1;
            mxY = max(mxY, cnt+1);
        }
        return min(mxX, mxY)*min(mxX, mxY);
    }
};