class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(m);
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                if(matrix[i][j]=='1')
                    row[j] += 1;
                else
                    row[j] = 0;
            
            vector<int> nsl(m,-1), nsr(m, m);
            stack<int> st;
            for(int j=0; j<m; j++){
                while(!st.empty() && row[st.top()] > row[j]){
                    nsr[st.top()] = j;
                    st.pop();
                }
                st.push(j);
            }
            while(!st.empty())
                st.pop();
            for(int j=m-1; j>=0; j--){
                while(!st.empty() && row[st.top()] > row[j]){
                    nsl[st.top()] = j;
                    st.pop();
                }
                st.push(j);
            }
            for(int j=0; j<m; j++){
                int l = nsr[j]-nsl[j]-1;
                int b = row[j];
                res = max(res, l*b);
            }
            cout<<endl;
        }
        return res;
    }
};