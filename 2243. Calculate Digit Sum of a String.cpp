class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            int i=0, n=s.size();
            string res = "";
            while(i<n){
                int sum = 0;
                for(int j=i; j<i+k && j<n; j++)
                    sum += (s[j]-'0');
                i += k;
                res += to_string(sum);
            }
            s = res;
        }
        return s;
    }
};