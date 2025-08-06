class SegTree{
  public: 
    vector<int> st;
    SegTree(int n){
        st.resize(4*n, -1);
    }
    void build(int i, int l, int r, vector<int>& baskets){
        if(l == r){
            st[i] = baskets[l];
            return;
        }
        int mid = l + (r-l)/2;
        build(2*i+1, l, mid, baskets);
        build(2*i+2, mid+1, r, baskets);
        st[i] = max(st[2*i+1], st[2*i+2]);
    }
    bool search(int i,int l, int r, int &fruit){
        if(fruit > st[i])
            return false;
        if(l == r){
            st[i] = -1;
            return true;
        }
        bool placed = false;
        int mid = l + (r-l)/2;
        if(st[2*i+1] >= fruit)
            placed = search(2*i+1, l, mid, fruit);
        else
            placed = search(2*i+2, mid+1, r, fruit);
        st[i] = max(st[2*i+1], st[2*i+2]);
        return placed;
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegTree seg(n);
        seg.build(0, 0, n-1, baskets);

        int cnt=0;
        for(int fruit : fruits){
            if(!seg.search(0, 0, n-1, fruit))
                cnt++;
        }
        return cnt;
    }
};