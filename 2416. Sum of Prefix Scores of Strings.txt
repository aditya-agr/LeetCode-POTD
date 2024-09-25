struct TrieNode{
    int cnt;
    TrieNode* child[26];

    TrieNode(){
        cnt = 0;
        for(int i=0; i<26; i++)
            child[i] = NULL;
    }
};

class Solution {
public:
    void insert(string str, TrieNode* root){
        TrieNode* curr = root;
        for(char c: str){
            int idx = c-'a';
            if(!curr->child[idx])
                curr->child[idx] = new TrieNode();
            curr = curr->child[idx];
            curr->cnt++;
        }
    }
    int search(string str, TrieNode*root){
        TrieNode* curr = root;
        int res=0;
        for(char c: str){
            int idx = c-'a';
            curr = curr->child[idx];
            res += curr->cnt;
        }
        return res;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode *root = new TrieNode();
        for(string str : words)
            insert(str, root);
        int n = words.size();
        vector<int> res(n);
        for(int i=0; i<n; i++)
            res[i] = search(words[i], root);
        return res;
    }
};