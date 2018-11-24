//Fast way-->binary way
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0)
            return NULL;
        return helper(lists,0,lists.size()-1);      
    }
private:
    ListNode * helper(vector<ListNode *> &lists ,int l,int r) //recursive until r == l, merge sort
    {
        if (l<r)
        {
            int m=(l+r)/2;
            return merge(helper(lists,l,m),helper(lists,m+1,r)); 
        }
        return lists[l];
    }
    ListNode * merge(ListNode *l1,ListNode *l2)
    {
        ListNode * out= new ListNode(0) ;
        ListNode * dummy =out;
        while ( l1 && l2)
        {
            if (l1->val<l2->val)
            {
                dummy->next=l1;
                l1=l1->next;
            }
            else
            {
                dummy->next=l2;
                l2=l2->next;
            }
            dummy=dummy->next;
        }
        if (l1)
            dummy->next=l1;
        if (l2)
            dummy->next=l2;
        return out->next;
        
    }
//Another way++++++++++++++++++++++++++
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
    struct comp {
        bool operator() (ListNode* a, ListNode* b) {
            if (a->val >= b->val)
                return true;
            else return false;
        }
        
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        queue<ListNode*> q;
        for(ListNode* l : lists) {
            if(l != nullptr)
                pq.push(l);
        }
        ListNode* ret = new ListNode(0);
        ListNode* save = ret;
        ListNode* curr;
        while(!pq.empty()) {
            curr = pq.top();
            pq.pop();
            if (curr != nullptr) {
                ret->next = curr;
                ret = ret->next;
            }
            if (ret->next != nullptr)
                pq.push(ret->next);
        }
        return save->next;
    }
};

//self
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        for (int i = 1; i<lists.size(); i++){
            lists[0]= mergeTwoLists(lists[0], lists[i]);            
        }
        return lists[0];
    }
       /* ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        ListNode* curr1 = l1, *curr2 = l2;
        for (; curr1 && curr2; curr=curr->next){
            if (curr1->val <= curr2->val){
                curr->next = curr1;
                curr1 = curr1->next;
            } else {
                curr->next = curr2;
                curr2 = curr2->next;
            }
        }
        curr->next = curr1? curr1:curr2;
        return dummy.next;
    }*/

    ListNode* mergeTwoLists(ListNode* A, ListNode* B){
        if (!A) return B;
        if (!B) return A;
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        if (A->val < B->val){
            curr->next = A;
            curr->next->next = mergeTwoLists(A->next, B);
        } else {
            curr->next = B;
            curr->next->next = mergeTwoLists(A, B->next);
        }
        return dummy.next;
    } 
};