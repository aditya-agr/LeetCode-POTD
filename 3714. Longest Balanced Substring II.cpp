class Solution {
public:
    int count(string &s, char a, char b){
        int n = s.length();
        int cnta = 0;
        int cntb = 0;
        int res = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            if(s[i]!=a && s[i]!=b){
                cnta = 0;
                cntb = 0;
                mp.clear();
                continue;
            }
            else if(s[i] == a) 
                cnta++;
            else if(s[i] == b)
                cntb++;
            if(cnta == cntb)
                res = max(res, cnta+cntb);
            int dif = cnta-cntb;
            if(mp.count(dif))
                res = max(res, i-mp[dif]);
            else
                mp[dif] = i;
        }
        return res;
    }
    int longestBalanced(string s) {
        int n = s.length();

        int cnt = 1;
        int res = 1;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1])
                cnt++;
            else{
                res = max(res, cnt);
                cnt = 1;
            }
        }
        res = max(res, cnt);

        res = max(res, count(s, 'a', 'b'));
        res = max(res, count(s, 'b', 'c'));
        res = max(res, count(s, 'a', 'c'));

        int cnta=0, cntb=0, cntc=0;
        map<pair<int, int>, int> mp;
        for(int i=0; i<n; i++){
            if(s[i] == 'a')
                cnta++;
            else if(s[i] == 'b')
                cntb++;
            else
                cntc++;
            
            if(cnta==cntb && cnta==cntc)
                res= max(res, cnta+cntb+cntc);
            
            int dif1 = cnta-cntb;
            int dif2 = cnta-cntc;
            pair<int, int> p = {dif1, dif2};
            if(mp.count(p))
                res = max(res, i-mp[p]);
            else
                mp[p] = i;   
        }
        return res;
    }
};