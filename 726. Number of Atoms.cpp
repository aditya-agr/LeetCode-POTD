class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());
        int i=0;
        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string, int>());
                i++;
            }
            else if(formula[i]==')'){
                unordered_map<string, int> curr = st.top();
                st.pop();
                i++;
                string numstr="";
                while(i<n && isdigit(formula[i])){
                    numstr += formula[i];
                    i++;
                }
                int num = numstr.empty() ? 1 : stoi(numstr);
                for(auto &it : curr){
                    curr[it.first] *= num;
                    st.top()[it.first] += curr[it.first];
                }
            }
            else{
                string ele="";
                ele += formula[i];
                i++;
                while(i<n && isalpha(formula[i]) && islower(formula[i])){
                    ele += formula[i];
                    i++;
                }
                string numstr="";
                while(i<n && isdigit(formula[i])){
                    numstr += formula[i];
                    i++; 
                }
                int num = numstr.empty() ? 1 : stoi(numstr);
                st.top()[ele] += num;
            }   
        }

        string res="";
        map<string, int> mp(st.top().begin(), st.top().end());
        for(auto &it : mp){
            res += it.first;
            if(it.second != 1) res += to_string(it.second);
        }
        return res;
    }
};