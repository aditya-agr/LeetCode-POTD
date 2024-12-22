class SegmentTree{
    vector<int>Seg;
public:
    SegmentTree(int n){
        Seg.resize(4*n+1);
    }
    void build(int l, int r, int i, vector<int> &nums){
        if(l==r){
            Seg[i] = l;
            return;
        }
        int mid = l + (r-l)/2;
        build(l, mid, 2*i+1, nums);
        build(mid+1, r, 2*i+2, nums);
        Seg[i] = (nums[Seg[2*i+1]] >= nums[Seg[2*i+2]]) ? Seg[2*i+1] : Seg[2*i+2];
    }
    int query(int l , int r, int st, int ed, int i, vector<int>&nums){
        if(l>ed || r<st)
            return -1;
        if(l>=st && r<=ed)
            return Seg[i];
        int mid = l + (r-l)/2;
        int left = query(l, mid, st, ed, 2*i+1, nums);
        int right = query(mid+1, r, st, ed, 2*i+2, nums);
        if(left == -1) return right;
        if(right == -1) return left;
        return (nums[left] >= nums[right]) ? left : right;
    }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        SegmentTree st(n);
        st.build(0, n-1, 0, heights);
        
        vector<int> res;
        for(vector<int> q : queries){
            int a = q[0];
            int b = q[1];
            if(a > b) swap(a, b);
            int ans = (heights[a] < heights[b] || a==b) ? b : -1;
            if(ans == -1){
                int low = b, high = n-1;
                ans = INT_MAX;
                while(low <= high){
                    int mid = low + (high-low)/2;
                    int req = st.query(0, n-1, low, mid, 0, heights);
                    if(heights[req] > heights[a]){
                        ans = min(ans, req);
                        high = mid-1;
                    }
                    else
                        low = mid+1;

                }
            }
            if(ans == INT_MAX) 
                res.push_back(-1);
            else
                res.push_back(ans);
        }
        return res;
    }
};