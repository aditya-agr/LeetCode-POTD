class Solution {
public:
    typedef pair<int, char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P, vector<P>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});
        string res="";
        while(!pq.empty()){
            int cnt = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            int n = res.length();
            if(n>1 && res[n-2]==ch && res[n-1]==ch){
                if(pq.empty()) break;
                int nxtcnt = pq.top().first;
                char nxtch = pq.top().second;
                pq.pop();
                res += nxtch;
                nxtcnt--;
                if(nxtcnt)
                    pq.push({nxtcnt, nxtch});
            }
            res += ch;
            cnt--;
            if(cnt)
                pq.push({cnt, ch});
        }
        return res;
    }
};