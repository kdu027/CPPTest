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
        //check if there are more than 1 node
        if(head == NULL || head->next == NULL) return head;
        ListNode* p = head->next;
        if (head->val == p->val){
            int val = head->val;
            while(p && val == p->val){
                ListNode* temp = p;
                p = p->next;
                delete temp;
            }
            delete head;
            return deleteDuplicates(p);
        } else{
            head->next = deleteDuplicates(p); //must scan the node one by one
            return head;
        }
    }
};