class Solution {
public:
    bool check(long long n, unordered_map<char, int> mp){
        string s = to_string(n);
        for(char c : s){
            if(mp.count(c) == 0)
                return false;
            mp[c]--;
            if(mp[c] == 0)
                mp.erase(c);
        }
        for(auto it : mp)
            if(it.second != 0)
                return false;
        return true;
    }
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        int len = s.length();
        long long it = 1;
        int l = 1;
        unordered_map<char, int> mp;
        for(char c : s)
            mp[c]++;
        vector<long long> vec;
        while(l <= len){
            if(l == len)
                vec.push_back(it);
            it *= 2;
            string t = to_string(it);
            l = t.length();
        }
        for(int v : vec){
            if(check(v, mp))
                return true;
        }
        return false;
    }
};