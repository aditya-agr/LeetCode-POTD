class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zero(n+1);
        for(int i=0; i<n; i++){
            int j = n-1;
            while(j>=0 && grid[i][j] == 0)
                j--;
            zero[i] = n-1-j;
        }
        int res = 0;
        for(int i=0; i<n; i++){
            int need = n-1-i;
            if(zero[i] >= need)
                continue;
            int j=i+1;
            while(j<n && zero[j] < need) 
                j++;
            if(j == n)
                return -1;
            while(zero[i] < need){
                swap(zero[j], zero[j-1]);
                j--;
                res++;
            }
        }
        return res;
    }
};