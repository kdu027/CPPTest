/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        for (ListNode* prev = head; (prev->next) != NULL;){
            ListNode*curr = prev->next;
            if (prev->val == curr->val){
                prev->next = curr->next;
                delete curr;
            } else{
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;    
    }
};