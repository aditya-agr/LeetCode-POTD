class Solution {
public:
    void rotate(vector<int> &a, int k){
        int n = a.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            res[i] = a[(i+k)%n];
        }
        a = res;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> tmp = mat;
        int n = mat.size();
        int m = mat[0].size();
        k = k%m;
        for(int i=0; i<n; i++){
            if(i%2 == 0)
                rotate(mat[i], k);
            else
                rotate(mat[i], m-k);
        }
        return mat == tmp;
    }
};