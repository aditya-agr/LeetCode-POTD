class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        int d = (n+1)/2;
        int low = pow(10, d-1);
        int high = pow(10, d) - 1;
        unordered_set<string> st;

        for(int i=low; i<=high; i++){
            string left = to_string(i);
            string full = "";
            if(n%2){
                string right = left.substr(0, d-1);
                reverse(right.begin(), right.end());
                full = left + right;
            }
            else{
                string right = left;
                reverse(right.begin(), right.end());
                full = left + right;
            }
            long long curr = stoll(full);
            if(curr%k)
                continue;
            sort(full.begin(), full.end());
            st.insert(full);
        }
        vector<long long> factorial(11, 1);
        for(int i=1; i<11; i++)
            factorial[i] = factorial[i-1]*i;
        
        long long res = 0;
        for(const string &s : st){
            vector<int> count(10, 0);
            for(const char &c : s)
                count[c-'0']++;
            int non0 = n - count[0];
            long long perm = non0 * factorial[n-1];
            for(int i=0; i<10; i++)
                perm /= factorial[count[i]];
            res += perm;
        }
        return res;
    }
};