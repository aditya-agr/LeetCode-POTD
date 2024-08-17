#define ll long long int
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<ll> prev(m);
        for(int i=0; i<m; i++)
            prev[i] = points[0][i];
        
        for(int row=1; row<n; row++){
            vector<ll> left(m);
            vector<ll> right(m);
            left[0] = prev[0];
            for(int i=1; i<m; i++)
                left[i] = max(prev[i], left[i-1]-1);

            right[m-1] = prev[m-1];
            for(int i=m-2; i>=0; i--)
                right[i] = max(prev[i], right[i+1]-1);

            vector<ll> curr(m);
            for(int i=0; i<m; i++)
                curr[i] = points[row][i] + max(left[i], right[i]);
                
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};