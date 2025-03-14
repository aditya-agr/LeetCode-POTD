class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long  total = 0;
        int maxC = 0;
        for(int c : candies){
            total += c;
            maxC = max(c, maxC);
        }
        if(total < k)
            return 0;
        
        int l = 1, h = maxC;
        int res = 1;
        while(l<=h){
            int mid = l + (h-l)/2;
            long long cnt = 0;
            for(int c : candies)
                cnt += c/mid;
            if(cnt >= k){
                res = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return res;
    }
};