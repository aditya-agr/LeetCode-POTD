class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> presum(n);
        presum[0] = (s[0]=='1');
        for(int i=1; i<n; i++)
            presum[i] = (s[i]=='1') + presum[i-1];

        int result = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int oneCount  = presum[j] - (i - 1 >= 0 ? presum[i-1] : 0);
                int zeroCount = (j - i + 1) - oneCount;

                if((zeroCount * zeroCount) > oneCount) {
                    //skip j to avoid waste indices
                    int wasteIndices = (zeroCount * zeroCount) - oneCount;
                    j += wasteIndices - 1;
                } else if((zeroCount * zeroCount) == oneCount) {
                    result += 1;
                } else {
                    result += 1;
                    int k = sqrt(oneCount) - zeroCount;
                    int next = j + k;

                    if(next >= n) { //out of bound, means all indices are valid
                        result += (n - j - 1);
                        break; //early break
                    } else {
                        result += k;
                    }

                    j = next;
                }
            }
        }

        return result;
    }
};