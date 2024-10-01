class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int x : arr){
            int rem = x%k;
            if(rem<0) rem+=k;
            mp[rem]++;
        }
        for(int i=1; i<=k/2; i++){
            if(mp[i] != mp[k-i])
                return false;
        }
        if(mp[0]%2)
            return false;
        return true;
    }
};
