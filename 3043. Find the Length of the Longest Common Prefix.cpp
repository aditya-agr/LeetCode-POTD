struct TrieNode{
    char digit;
    TrieNode *child[10];

    TrieNode (){
        digit = '0';
        for(int i=0; i<10; i++)
            child[i] = NULL;
    }
};

class Solution {
public:
    void insert(int num, TrieNode* root){
        TrieNode *curr = root;
        string str = to_string(num);
        for(char c : str){
            int idx = c-'0';
            if(!curr->child[idx])
                curr->child[idx] = new TrieNode();
            curr = curr->child[idx];
        }
    }
    int search(int num, TrieNode *root){
        TrieNode *curr = root;
        string str = to_string(num);
        int len=0;
        for(char c : str){
            int idx = c-'0';
            if(curr->child[idx]){
                len++;
                curr = curr->child[idx];
            }
            else
                break;
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode *root = new TrieNode();
        for(int it : arr1)
            insert(it, root);
        int res=0;
        for(int it : arr2)
            res = max(res, search(it, root));
        return res;

    }
};