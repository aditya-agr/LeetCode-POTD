class Solution {
public:
    int check(vector<int>& bloomDay, int day, int k){
        int cnt=0;
        int flower=0;
        for(auto &iday : bloomDay){
            if(iday<=day)
                flower++;
            else
                flower=0;
            if(flower==k){
                cnt++;
                flower=0;
            }
        }
        return cnt;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1;
        int h=*max_element(bloomDay.begin(), bloomDay.end());
        int res=-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(check(bloomDay, mid, k) >= m){
                res = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};