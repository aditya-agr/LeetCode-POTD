#define pii pair<int,int>
class Solution {
public:
    unordered_map<int, int> freq;
    set<pii, greater<pii>> top, rest;
    long long sum = 0;
    void insert_(int v, int x){
        int f = freq[v];
        freq[v]++;
        if(f > 0){
            auto it = top.find({f, v});
            if(it != top.end()){
                top.erase(it);
                sum -= 1LL*f*v;
            }
            else
                rest.erase({f, v});
        }

        top.insert({++f, v});
        sum += 1LL*f*v;

        if(top.size() > x){
            auto it = prev(top.end());
            sum -= 1LL*it->first*it->second;
            rest.insert(*it);
            top.erase(it);
        }
    }
    void erase_(int v, int x){
        int f = freq[v];
        freq[v]--;
        auto it = top.find({f, v});
        if(it != top.end()){
            sum -= 1LL*f*v;
            top.erase(it);
        }
        else
            rest.erase({f, v});
        
        if(f-1 == 0)
            freq.erase(v);
        else
            rest.insert({--f, v});

        if(top.size()<x && rest.size()>0){
            auto it = rest.begin();
            sum += 1LL*it->first*it->second;
            top.insert(*it);
            rest.erase(it);
        }
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> res(n-k+1);
        for(int i=0; i<k; i++)
            insert_(nums[i], x);
        res[0] = sum;
        for(int i=k; i<n; i++){
            erase_(nums[i-k], x);
            insert_(nums[i], x);
            res[i-k+1] = sum;
        }
        return res;
    }
};