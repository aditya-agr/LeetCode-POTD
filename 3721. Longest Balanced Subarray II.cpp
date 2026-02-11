class SegmentTree{
    vector<int> mn, mx, lazy;
public:
    SegmentTree(int n){
        mn.resize(4*n);
        mx.resize(4*n);
        lazy.resize(4*n);
    }
    void propogate(int i, int l, int r){
        if(lazy[i] != 0){
            mn[i] += lazy[i];
            mx[i] += lazy[i];
            if(l != r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }
    void update(int l, int r, int i, int st, int ed, int val){
        propogate(i, st, ed);
        if(st>r || ed<l)
            return;
        if(st>=l && ed<=r){
            lazy[i] += val;
            propogate(i, st, ed);
            return;
        }
        int mid = st+(ed-st)/2;
        update(l, r, 2*i+1, st, mid, val);
        update(l, r, 2*i+2, mid+1, ed, val);
        mn[i] = min(mn[2*i+1], mn[2*i+2]);
        mx[i] = max(mx[2*i+1], mx[2*i+2]);
    }
    int search(int i, int st, int ed){
        propogate(i, st, ed);
        if(mn[i]>0 || mx[i]<0)
            return -1;
        if(st == ed)
            return st;
        int mid = st+(ed-st)/2;
        int l = search(2*i+1, st, mid);
        if(l != -1)
            return l;
        return search(2*i+2, mid+1, ed);
    }
};
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SegmentTree seg(n);
        unordered_map<int, int> mp;
        int res = 0;
        for(int r=0; r<n; r++){
            int val = (nums[r]%2) ? -1 : 1;
            int prev = -1;
            if(mp.count(nums[r]))
                prev = mp[nums[r]];
            if(prev != -1)
                seg.update(0, prev, 0, 0, n-1, -val);
            seg.update(0, r, 0, 0, n-1, val);
            int l = seg.search(0, 0, n-1);
            if(l != -1)
                res =  max(res, r-l+1);
            mp[nums[r]] = r;
        }
        return res;
    }
};