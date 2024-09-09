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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> res(n, vector<int>(m, -1));
        int top=0, bottom=n-1, left=0, right=m-1;
        while(head){
            for(int i=left; i<=right && head; i++){
                res[top][i] = head->val;
                head = head->next;
            }
            top++;
            for(int i=top; i<=bottom && head; i++){
                res[i][right] = head->val;
                head = head->next;
            }
            right--;
            for(int i=right; i>=left && head; i--){
                res[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;
            for(int i=bottom; i>=top && head; i--){
                res[i][left] = head->val;
                head = head->next;
            }
            left++;
        }
        return res;
    }
};