#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    ll mod = 1e9+7;
    void computeScore(vector<ll> &score, vector<int>&nums){
        for(ll ele: nums){
            ll count = 0;
            for(ll i=2; i*i<ele; i++){
                if(ele%i == 0)
                    count ++;
                while(ele%i == 0)
                    ele /= i;
            }
            if(ele>1) count++;
            score.push_back(count);
        }
    }
    void computeMaxCount(vector<ll> &maxCount, vector<ll> &score){
        ll n = score.size();
        vector<ll> pge(n);
        stack<ll> st;
        for(ll i=0; i<n; i++){
            while(!st.empty() && score[st.top()] < score[i])
                st.pop();
            if(st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();
            st.push(i);
        }
        st = stack<ll>();
        ll count;
        for(ll i=n-1; i>=0; i--){
            while(!st.empty() && score[st.top()] <= score[i])
                st.pop();
            if(st.empty())
                count = (n-i)*(i-pge[i]);
            else
                count = (st.top()-i)*(i-pge[i]);
            maxCount[i] = count;
            st.push(i);
        }
    }
    ll binExponent(ll x, ll n){
        ll res = 1;
        while(n){
            if(n%2)
                res = (res*x)%mod;
            x = (x*x)%mod;
            n /= 2;
        }
        return res%mod;
    }
    ll maximumScore(vector<int>& nums, ll k) {
        ll n = nums.size();
        vector<ll> score;
        computeScore(score, nums);

        vector<ll> maxCount(n);
        computeMaxCount(maxCount, score);

        priority_queue<pll> pq;
        for(ll i=0; i<n; i++)
            pq.push({nums[i], i});
        
        ll res = 1;
        while(k > 0){
            ll num = pq.top().first;
            ll idx = pq.top().second;
            pq.pop();
            res = (res * binExponent(num, min(k, maxCount[idx])))%mod;
            k -= maxCount[idx];
        }
        return res;
    }
};