class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        for(char c : allowed)
        	st.insert(c);
            int ans=0;
            for(string s : words){
            	int flag=1;
                for(char c : s)
            		if(st.count(c) == 0)
                    	flag=0;
                if(flag)
                    ans++;
            }
        return ans;
    }
};