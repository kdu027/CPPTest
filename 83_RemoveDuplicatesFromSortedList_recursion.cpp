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
        if (head == NULL) return head;
        ListNode dummy(head->val-1);
        ListNode* head2 = &dummy;
        head2->next = head;
        removeDuplicates(head2, head);
            return dummy.next;
    }
private: 
    void removeDuplicates(ListNode* prev, ListNode* curr){
        if (curr == NULL) return;
        if (curr->val == prev->val){
            prev->next = curr->next;
            delete curr;
            removeDuplicates(prev, prev->next);
        } else{
            removeDuplicates(prev->next, curr->next);
        }
        return;
    }
};