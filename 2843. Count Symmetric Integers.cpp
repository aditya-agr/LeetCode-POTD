class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i=low; i<=high; i++){
            string s = to_string(i);
            int n = s.length();
            if(n%2)
                continue;
            int a=0, b=0;
            for(int i=0; i<n/2; i++){
                a += ('0'-s[i]);
                b += ('0'-s[n-1-i]);
            }
            if(a == b)  
                cnt++;
        }
        return cnt;
    }
};