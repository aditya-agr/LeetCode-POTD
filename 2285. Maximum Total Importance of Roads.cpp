class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> a(n);
        for(auto &i : roads){
            a[i[0]]++;
            a[i[1]]++;
        }
        sort(a.begin(), a.end());
        long long res=0;
        for(int i=0; i<n; i++)
            res += a[i]*(i+1);
        return res;
    }
};