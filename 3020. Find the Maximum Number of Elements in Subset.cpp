class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x : nums){
            mp[x]++;
        }
        int res = 1;
        for(int x : nums){
            if(x == 1){
                res = max(res, mp[1] - (mp[1]%2 ? 0 : 1));
                continue;
            }
            int cur = x, len = 1;
            while(mp.count(cur)){
                long long t = 1LL*cur*cur;
                if(t > 1e9+5)
                    break;
                if(mp[cur]>=2 && mp.count(cur*cur))
                    len += 2;
                else
                    break;
                cur *= cur;
            }
            res = max(res, len);
        }
        return res;
    }
};