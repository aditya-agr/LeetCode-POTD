class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int n = happiness.size();
        long long sum=0;
        for(int i=n-1, j=0; i>=n-k; i--, j++)
            sum += (happiness[i]-j<0) ? 0 : happiness[i]-j;
        return sum;
    }
};