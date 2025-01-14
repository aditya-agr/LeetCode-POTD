class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> idx(n+1), C(n);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(idx[A[i]]) cnt++;
            idx[A[i]]++;
            if(idx[B[i]]) cnt++;
            idx[B[i]]++;
            C[i] = cnt;
        }
        return C;
    }
};