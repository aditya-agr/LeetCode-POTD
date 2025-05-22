class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        priority_queue<int, vector<int>, greater<int>> used;
        priority_queue<int> avail;
        sort(queries.begin(), queries.end());

        int qidx = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            while(qidx < q && queries[qidx][0]==i)
                avail.push(queries[qidx++][1]);
            
            nums[i] -= used.size();

            while(nums[i]>0 && !avail.empty() && avail.top()>=i){
                used.push(avail.top());
                avail.pop();
                nums[i]--;
                cnt++;
            }
            if(nums[i]>0) return -1;
            while(!used.empty() && used.top()==i)
                used.pop();
        }
        return q-cnt;
    }
};