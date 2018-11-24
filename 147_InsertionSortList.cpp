//++++++++++++++self-write+++++++++++++++
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
    ListNode* insertionSortList(ListNode* head) {
        // check if head is NULL
        if (!head || !head->next) return head;
        ListNode* sorted = NULL, *curr = head;
        while (curr){
            ListNode* next = curr->next; //curr may be changed
            sortList(&sorted, curr);
            curr = next;
        }
        return sorted;
    }
private: 
    void sortList(ListNode** head_ref, ListNode* curr){
        if (!head_ref) return;
        if (*head_ref == NULL || (*head_ref)->val > curr->val){ //two conditions can be put together
            curr->next = *head_ref;
            *head_ref = curr;
        } else {
            ListNode* head = *head_ref;
            while (head->next && head->next->val <= curr->val){
                head = head->next;
            }
            curr->next = head->next;
            head->next = curr;
        }
        return;
    }
};
//++++++++++++++12ms way+++++++++++++++++++++++++=
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
    ListNode* insertionSortList(ListNode* head) {
        
     if (!head) return head;
		ListNode* tail = head->next;
		ListNode* tmp = head, *prev = head, *last = head;
		while (tail)
		{
			if (tail->val < prev->val)
			{
				tmp = head;
				last = head;
				while (tmp->val <= tail->val)
				{
					last = tmp;
					tmp = tmp->next;
				}
				if (tmp == head && last == head)
				{
					 head = tail; 
				}
				else
				{
					 last->next = tail;
				}
				prev->next = tail->next; tail->next = tmp; tail = prev->next;
			}
			else
			{
				prev = tail;
				tail = tail->next;
			}
		}
		return head;
	}
};
//++++++++++++++++++++++++16ms merge sort way++++++++++++++
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
    
    
    void split(ListNode *head,ListNode **start,ListNode **end)
    {
        ListNode *first=head;
        ListNode *second=head->next;
        while(first && second && second->next)
        {
            first=first->next;
            second=second->next->next;
        }
        *end=first->next;
        first->next=NULL;
        *start=head;
    }
    
    ListNode *merge(ListNode *start,ListNode *end)
    {
        if(!start)
            return end;
        if(!end)
            return start;
        if(start->val<=end->val)
        {
            start->next=merge(start->next,end);
            return start;
        }
        else
        {
            end->next=merge(start,end->next);
            return end;
        }
    }
    
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *start=NULL;
        ListNode *end=NULL;
        split(head,&start,&end);
        start=insertionSortList(start);
        end=insertionSortList(end);
        return merge(start,end);
    }
};