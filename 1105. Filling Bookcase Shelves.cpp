class Solution {
public:
    int width;
    int n;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& books, int i, int rem, int mxh){
        if(i>=n)
            return mxh;
        if(dp[i][rem]!=-1)
            return dp[i][rem];
        int currh = books[i][1];
        int currw = books[i][0];
        int skip=INT_MAX, put=INT_MAX;
        if(currw<=rem)
            put = solve(books, i+1, rem-currw, max(mxh, currh));
        skip = mxh + solve(books, i+1, width-currw, currh);
        return dp[i][rem] = min(put, skip);        

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        width = shelfWidth;
        dp.assign(n+1, vector<int>(width+1, -1));
        return solve(books, 0, width, 0);
    }
};