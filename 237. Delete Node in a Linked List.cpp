class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev;
        while(node->next){
            prev = node;
            node->val = node->next->val;
            node = node->next;
        }
        prev->next = NULL;
    }
};