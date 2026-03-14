class Solution {
public:
    char nextgreater(char c){
        if(c == 'a') return 'c';
        if(c == 'b') return 'c';
        return 'b';
    }
    char nextsmaller(char c){
        if(c == 'a') return 'b';
        if(c == 'b') return 'a';
        return 'a';
    }
    string getHappyString(int n, int k) {
        int l = 1, h = 3;
        for(int i=1; i<n; i++)
            h *= 2;
        string ans="";
        if(k > h)
            return ans;

        if(k > h/3 && k <= h*2/3){
            l = h/3+1;
            h = h*2/3;
            ans += 'b';
        }
        else if(k > h*2/3){
            l = h*2/3+1;
            ans += 'c';
        }
        else if(k <= h/3){
            h = h/3;
            ans += 'a';
        }
        while(l<h){
            int mid = l + (h-l)/2;
            if(mid < k){
                ans += nextgreater(ans.back());
                l = mid+1;
            }
            else{
                ans += nextsmaller(ans.back());
                h = mid;
            }
        }
        return ans;
    }
};