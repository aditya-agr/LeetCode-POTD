class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0)
            return {};
        vector<int> t = arr;
        sort(t.begin(), t.end());
        unordered_map<int, int> mp;
        mp[t[0]] = 1;a
        int r = 1;
        for(int i=1; i<n; i++){
            if(t[i] != t[i-1])
                r++;
            mp[t[i]] = r;
        }

        vector<int> res(n);
        for(int i=0; i<n; i++){
            res[i] = mp[arr[i]];
        }
        return res;
        
    }
};