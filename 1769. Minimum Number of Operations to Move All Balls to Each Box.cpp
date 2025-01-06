class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--)
                res[i] += (boxes[j]=='1') ? (i-j) : 0;
            for(int j=i+1; j<n; j++)
                res[i] += (boxes[j]=='1') ? (j-i) : 0;
        }
        return res;
    }
};