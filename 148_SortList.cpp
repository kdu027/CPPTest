//self write
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
    ListNode* sortList(ListNode* head) {
        //check head is NULL
        if (!head || !head->next) return head;
        //split the list
        ListNode* prev=NULL, *slow=head, *fast=head;
        while (fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* head1=sortList(head);
        ListNode* head2 = sortList(slow);
        head = mergeSort(head1, head2);
        return head;
    }
private:
    ListNode* mergeSort(ListNode* head1, ListNode* head2){
        if(!head1) return head2;
        if(!head2) return head1;
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        if (head1->val < head2->val){
            curr->next = head1;
            curr = curr->next;
            curr->next = mergeSort(head1->next, head2);
        } else {
            curr->next = head2;
            curr = curr->next;
            curr->next = mergeSort(head1, head2->next);
        }
        return dummy.next;
    }
};
//+++++++++other way++++++++++
class Solution {
public:
    
    ListNode *merge(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *dummyHead = new ListNode(0);
        
        ListNode *node = dummyHead;
        while(l1 && l2) {
            if (l1->val <= l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        
        if (l1)
            node->next = l1;
        if (l2)
            node->next = l2;
        
        node = dummyHead->next;
        delete dummyHead;
        return node;
    }
 
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode *s = head, *f = head->next;
        
        while(f && f->next) {
            f = f->next->next;
            s = s->next;
        }
        
        ListNode *left, *right;
        left = head, right = s->next;
        s->next = NULL;
        
        left = sortList(left);
        right = sortList(right);
   
        return merge(left, right);
    }
};