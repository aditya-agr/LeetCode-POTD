class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int unsatis=0, satis=0;
        int n=customers.size();
        for(int i=0; i<minutes; i++){
            unsatis += customers[i]*grumpy[i];
            satis += customers[i]*(grumpy[i]^1);
        }
        int i=0, j=minutes, mx=unsatis;
        while(j<n){
            unsatis += customers[j]*grumpy[j];
            unsatis -= customers[i]*grumpy[i];
            mx = max(mx, unsatis);
            satis += customers[j]*(grumpy[j]^1);
            i++; j++;
        }
        return mx+satis;
    }
};