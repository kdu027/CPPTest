//myself write
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return; //don't forget NULL list
        ListNode* prev = NULL, *slow=head, *fast=head;
        while (fast && fast->next){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;  
        }
        prev->next = NULL;
        slow = reverse(slow);  
        head = merge(head, slow);
        return;        
    }
private:
    ListNode* merge(ListNode* curr1, ListNode* curr2){
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        while (curr1 || curr2){
            if(curr1){
                curr->next = curr1;
                curr1 = curr1->next;
                curr = curr->next;
            }
            if(curr2){
                curr->next = curr2;
                curr2 = curr2->next;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
    ListNode* reverse(ListNode* head){
        if (!head || !head->next) return head;
        ListNode* prev = NULL;
        for (ListNode* curr = head; curr;){//no need to curr=curr->next because curr has been updated by temp
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};//+++++++++++++++++++++++++=

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
    ListNode* reverse(ListNode* ptr)
    {
        if(!ptr || !ptr->next)
            return ptr;
        ListNode* sec = ptr->next;
        ListNode* rsec = reverse(sec);
        sec->next = ptr;
        ptr->next = NULL;
        return rsec;
    }
    
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
      
        while(a || b)
        {
            if(a)
            {
                ptr->next= a;
                a = a->next;
                ptr = ptr->next;
            }
            if(b)
            {
                ptr->next = b;
                b = b->next;
                ptr = ptr->next;
            }
        }
        
        return dummy->next;
    }
    void reorderList(ListNode* head) {
        
        if(!head || !head->next)
            return ;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;
        while(fast && fast->next)
        {
            prev = slow;
            slow= slow->next;
            fast = fast->next->next;
        }
        
        // 1 2 |3| 4
        // 1 2 |3| 4 5
        prev->next = NULL;
        ListNode* rstring = reverse(slow);
        
       head=   merge( head, rstring);
        return ;
    }
};