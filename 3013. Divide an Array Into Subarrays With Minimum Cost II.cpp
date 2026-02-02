class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> P;

    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<P> res;
        set<P> rem;
        int i = 1;
        ll sum = 0;
        while(i-dist < 1){
            res.insert({nums[i], i});
            sum += nums[i];
            if(res.size() > k-1){
                P temp = *res.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                res.erase(temp);
            }
            i++;
        }
        ll ans = LLONG_MAX;
        while(i < n){
            res.insert({nums[i], i});
            sum += nums[i];
            if(res.size() > k-1){
                P temp = *res.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                res.erase(temp);
            }
            ans = min(ans, sum);
            P temp = {nums[i-dist], i-dist};
            if(res.count(temp)){
                res.erase(temp);
                sum -= nums[i-dist];
                if(!rem.empty()){
                    P it = *rem.begin();
                    res.insert(it);
                    sum += it.first;
                    rem.erase(it);
                }
            }
            else{
                rem.erase(temp);
            }
            i++;
        }
        return nums[0]+ans;
    }
};