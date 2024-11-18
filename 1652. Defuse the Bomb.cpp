class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n,0);
        if(k==0)
            return res;
        else if(k>0){
            int sum = 0, j = k;
            for(int i=0; i<k; i++)
                sum += code[i];
            for(int i=0; i<n; i++){
                sum += code[j];
                sum -= code[i];
                res[i] = sum;
                j = (j+1)%n;
            }
        }
        else{
            int sum = 0, j = n+k;
            for(int i=0; i<abs(k); i++)
                sum += code[(n-i-1)%n];
            for(int i=0; i<n; i++){
                res[i] = sum;
                sum += code[i];
                sum -= code[j];
                j = (j+1)%n;
            }
        }
        return res;
    }
};