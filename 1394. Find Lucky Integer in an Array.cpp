class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> f;
        for(int &x : arr)
            f[x]++;
        int res = -1;
        for(int &x : arr){
            if(f[x] == x)
                res = max(res, x);
        }
        return res;
    }
};