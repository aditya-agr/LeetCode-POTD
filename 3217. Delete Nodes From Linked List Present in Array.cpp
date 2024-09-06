/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* nhead = new ListNode(0);
        nhead->next = head;
        ListNode *curr=head, *prev=nhead;
        while(curr){
            if(st.count(curr->val))
                prev->next = curr->next;
            else
                prev = prev->next;
            curr = curr->next;
        }
        return nhead->next;
    }
};