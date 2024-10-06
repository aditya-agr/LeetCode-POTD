class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.size() < sentence2.size())
            swap(sentence1, sentence2);
        vector<string> s1;
        stringstream ss1(sentence1);
        string token;
        while(ss1>>token)
            s1.push_back(token);

        vector<string> s2;
        stringstream ss2(sentence2);
        while(ss2>>token)
            s2.push_back(token);
        int i=0, j=s1.size()-1;
        int k=0, l=s2.size()-1;
        while(i<=j && k<=l && s1[i]==s2[k]){
            cout<<s1[i]<<":"<<s2[k];
            i++;
            k++;
        }
        while(k<=l && s1[j]==s2[l]){
            j--;
            l--;
        }
        return l<k;
    }
};