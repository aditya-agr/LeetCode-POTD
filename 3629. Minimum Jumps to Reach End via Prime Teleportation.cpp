class Solution {
public:
    vector<bool> isprime;
    void buildSieve(int n){
        isprime.resize(n+1, true);
        isprime[0] = false;
        isprime[1] = false;
        for(int i=2; i*i<=n; i++){
            if(isprime[i]){
                for(int j=i*i; j<=n; j+=i)
                    isprime[j] = false; 
            }
        }
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        int mxele = 0;
        for(int i=0; i<n; i++){
            mxele = max(mxele, nums[i]);
            mp[nums[i]].push_back(i);
        } 
        buildSieve(mxele);

        queue<int> q;
        q.push(0);
        vector<bool> vis(n, false);
        vis[0] = true;
        unordered_set<int> st;
        int steps = 0;
        while(!q.empty()){
            int m = q.size();
            for(int i=0; i<m; i++){
                int idx = q.front();
                q.pop();
                if(idx == n-1)
                    return steps;
                if(idx+1<n && !vis[idx+1]){
                    q.push(idx+1);
                    vis[idx+1] = true;
                }
                if(idx-1>=0 && !vis[idx-1]){
                    q.push(idx-1);
                    vis[idx-1] = true;
                }
                if(!isprime[nums[idx]] || st.count(nums[idx]))
                    continue;
                for(int mul=nums[idx]; mul<=mxele; mul+=nums[idx]){
                    if(!mp.contains(mul))
                        continue;
                    for(int &j : mp[mul]){
                        if(!vis[j]){
                            q.push(j);
                            vis[j] = true;
                        }
                    }
                }
                st.insert(nums[idx]);
            }
            steps++;
        }
        return steps;
    }
};