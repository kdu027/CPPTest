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
    ListNode* partition(ListNode* head, int x) {
        ListNode leftDummy(-1);
        ListNode rightDummy(-1);
        ListNode* left_curr = &leftDummy;
        ListNode* right_curr = &rightDummy;
        for(auto curr = head; curr; curr=curr->next){
            if (curr->val < x) {
                left_curr->next = curr;
                left_curr = left_curr->next;
            } else {
                right_curr->next = curr;
                right_curr = right_curr->next;
            }
        }
        //connect left and right
        left_curr->next = rightDummy.next;
        right_curr->next = NULL;
        return leftDummy.next;
    }
};