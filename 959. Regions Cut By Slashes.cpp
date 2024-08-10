class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int cnt;
    
    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
 
        if(x_parent!=y_parent){
            if(rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
        }
        else
            cnt++;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int V = (n+1);
        parent.resize(V*V);
	    rank.resize(V*V, 0);
	    for(int i = 0; i<V*V; i++)
	        parent[i] = i;

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(i==0 || j==0 || i==n || j==n){
                    int cell = i*V + j;
                    // if(cell != 0) 
                    Union(0,cell);
                }
            }
        }
	    cnt=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='/'){
                    int c1 = i*V + (j+1);
                    int c2 = (i+1)*V + j;
                    Union(c1, c2);
                }
                else if(grid[i][j] == '\\'){
                    int c1 = i*V + j;
                    int c2 = (i+1)*V + (j+1);
                    Union(c1, c2);
                }
            }
        }
        return cnt;
    }
};