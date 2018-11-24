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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k==0) return head;
        int len = 1;
        ListNode* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
            len++;
        }
        int k2 = k%len;
        curr->next = head;
        for (int i=0; i<(len-k2); i++){
            curr = curr->next;
        }
        ListNode* newHead = curr->next;
        curr->next = NULL;
        return newHead;
    }
};