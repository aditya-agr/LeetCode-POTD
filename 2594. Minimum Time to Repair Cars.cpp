class Solution {
public:
    bool isPossible(vector<int>& ranks, int cars, long long time){
        long long cnt = 0;
        for(int rank : ranks)
            cnt += sqrt(time/rank);
        return cnt >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long l = 1;
        int maxi = *max_element(ranks.begin(), ranks.end());
        long long h = 1LL*maxi*cars*cars;
        long long res = -1;
        while(l<=h){
            long long mid = l + (h-l)/2;
            if(isPossible(ranks, cars, mid)){
                res = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};