class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>mp;
        for(char i : tasks)
            mp[i]++;
        priority_queue<int>pq;
        for(auto i : mp)
            pq.push(i.second);
        int res=0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=1; i<=n+1 && !pq.empty(); i++){
                int fr = pq.top();
                fr--;
                pq.pop();
                temp.push_back(fr);
            }   
            for(int f : temp){
                if(f) 
                    pq.push(f);
            }
            if(pq.empty())
                res+=temp.size();
            else
                res+=n+1;
        }
        return res;
    }
};