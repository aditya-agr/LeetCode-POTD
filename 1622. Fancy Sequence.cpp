#define ll long long 
class Fancy {
public:
    ll mod = 1e9+7;
    vector<ll> seq;
    ll add, mul;

    Fancy() {
        add = 0;
        mul = 1;
    }
    
    ll power(ll a, ll b){
        if(b == 0)
            return 1;
        ll half = power(a, b/2);
        ll res = (half*half)%mod;
        if(b%2 == 1)
            res = (res*a)%mod;
        return res;
    }

    void append(int val) {
        ll num = ((val-add)%mod + mod) * power(mul, mod-2)%mod;    
        seq.push_back(num);
    }
    
    void addAll(int inc) {
        add = (add + inc)%mod;
    }
    
    void multAll(int m) {
        add = (add * m)%mod;
        mul = (mul * m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx >= seq.size())
            return -1;
        return (seq[idx]*mul + add)%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */