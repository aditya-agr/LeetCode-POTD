class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n-1;
        while(j>0 && arr[j]>=arr[j-1])
            j--;
        int res = j;
        while(i<j && (i==0 || arr[i]>=arr[i-1])){
            while(j<n && arr[j]<arr[i])
                j++;
            res = min(res, j-i-1);
            i++;
        }
        return res;
    }
};