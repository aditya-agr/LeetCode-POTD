class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        auto comp = [](vector<string> a, vector<string> b){
            if(stoi(a[1]) < stoi(b[1]))
                return true;
            else if(stoi(a[1]) > stoi(b[1]))
                return false;
            return a[0] == "OFFLINE";
        };
        sort(events.begin(), events.end(), comp);
        vector<int> res(n), online(n, 0);
        for(vector<string> e : events){
            string type = e[0];
            int time = stoi(e[1]);
            if(type == "MESSAGE"){
                if(e[2] == "HERE"){
                    for(int i=0; i<n; i++){
                        if(online[i] <= time)
                            res[i]++;
                    }
                }
                else if(e[2] == "ALL"){
                    for(int i=0; i<n; i++)
                        res[i]++;
                }
                else{
                    string mention = e[2]+" ", id = "";
                    for(char c : mention){
                        if(c == ' '){
                            int i = stoi(id);
                            res[i]++;
                            id = "";
                        }
                        else if(c >= '0' && c <= '9')
                            id += c;
                    }
                }
                
            }
            else{
                int id = stoi(e[2]);
                online[id] = time + 60;
            }
        }
        return res;
    }
};