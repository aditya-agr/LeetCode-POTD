class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for(int i=num1; i<=num2; i++){
            string s = to_string(i);
            int n = s.length();
            if(n < 3)
                continue;
            for(int j=1; j<n-1; j++){
                if(s[j-1]<s[j] && s[j+1]<s[j])
                    res++;
                if(s[j-1]>s[j] && s[j+1]>s[j])
                    res++;
            }
        }
        return res;
    }
};