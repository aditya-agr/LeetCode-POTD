class Solution {
public:
    long long process(long long num, int flag){
        string a, b;
        a = b = to_string(num);
        if(flag)
            b.pop_back();
        reverse(b.begin(), b.end());
        string res = a + b;
        return stol(res);
    }
    string nearestPalindromic(string n) {
        long long num = stol(n);
        int len = n.length();
        if(len == 1)
            return to_string(num-1);

        vector<long long> cand;
        cand.push_back(pow(10, len) + 1); 
        cand.push_back(pow(10, len-1) - 1); 

        int hlen = (len+1)/2;
        string hstr = n.substr(0, hlen);
        long long half = stol(hstr);
        int flag = (len%2) ? 1:0;
        cand.push_back(process(half+1, flag));
        cand.push_back(process(half, flag));
        cand.push_back(process(half-1, flag));

        long long mindiff=INT_MAX, res;
        for(auto it : cand){
            if (it == num) continue;
            long long curr = abs(it-num);
            if(curr<mindiff){
                res = it;
                mindiff = curr;
            }
            else if(curr == mindiff)
                res = min(it, res);
        }
        return to_string(res);    
    }
};