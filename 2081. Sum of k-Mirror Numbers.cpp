class Solution {
public:
    bool isPalindrome(string &s){
        int n = s.length();
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
    bool isKmirror(string &s, int k){
        long long num = stoll(s);
        string res = "";
        while(num){
            res += (num%k + '0');
            num = num/k;
        }
        reverse(res.begin(), res.end());
        return isPalindrome(res);
    }
    long long kMirror(int k, int n) {
        int l=1;
        long long sum = 0;
        while(n){
            int half = (l+1)/2;
            long long mn = pow(10, half-1);
            long long mx = pow(10, half) - 1;
            for(long long i=mn; i<=mx; i++){
                string f = to_string(i);
                string s = f;
                reverse(s.begin(), s.end());
                string num;
                if(l%2 == 0)
                    num = f + s;
                else
                    num = f + s.substr(1);
                
                if(isKmirror(num, k)){
                    sum += stoll(num);
                    n--;
                    if(n == 0)
                        break;
                }
            }
            l++;
        }
        return sum;
    }
};