class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        if(words[startIndex] == target)
            return 0;
        int cnt = 1;
        int res = INT_MAX;
        for(int i=(startIndex+1)%n; i!=startIndex; i=(i+1)%n){
            if(words[i] == target){
                res = min(res, cnt);
                break;
            }
            cnt++;
        }
        cnt = 1;
        for(int i=(startIndex-1+n)%n; i!=startIndex; i=(i-1+n)%n){
            if(words[i] == target){
                res = min(res, cnt);
                break;
            }
            cnt++;
        }
        return res == INT_MAX ? -1 : res;
    }
};