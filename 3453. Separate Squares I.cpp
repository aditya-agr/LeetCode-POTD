class Solution {
public:
    double check(vector<vector<int>>& squares, double mid, double sum){
        double tot = 0;
        for(vector<int> &x : squares){
            double s = x[2];
            double y = x[1];
            if(y >= mid)
                continue;
            else if(y+s <= mid)
                tot += s*s;
            else{
                double num = mid-y;
                tot += num*s;
            }
        }
        return tot >= sum;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double sum = 0;
        double mxY = INT_MIN, mnY = INT_MAX;
        for(vector<int> &x : squares){
            double s = x[2];
            double y = x[1];
            sum += s*s;
            mxY = max(mxY, s+y);
            mnY = min(mnY, y);
        }
        sum /= 2.0;
        double l = mnY, r = mxY;
        double epsilon=1e-5;
        while(r-l > epsilon){
            double mid = (l+r)/2.0;
            if(check(squares, mid, sum))
                r = mid;
            else
                l = mid;
        }
        return (l+r)/2;
    }
};