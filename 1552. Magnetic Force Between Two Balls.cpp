class Solution {
public:
    bool check(vector<int>& p, int x, int m){
        int it=p[0]+x;
        int t = m-1;
        for(int i=1; i<p.size(); i++){
            if(p[i]>=it){
                t--;
                it = p[i]+x;
            }
        }
        return t<=0;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, n = position.size();
        int h = (position[n-1]-position[0])/(m-1);
        int mx=0;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(check(position, mid, m)){
                mx = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return mx;
    
    }
};