//self write
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        for (ListNode* curr = head; curr; curr = curr->next) size++;
        return _sortedListToBST(head, 0, size-1);
    }
    TreeNode* _sortedListToBST(ListNode*& head, int start, int end){
        if (start > end) return NULL;
        int mid = (start + end)/2;
        TreeNode* left = _sortedListToBST(head, start, mid-1);
        TreeNode* root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = _sortedListToBST(head, mid+1, end);
        return root;
    }
};
//Another way++++++++++++++++++++++++++++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = countLNodes(head); 
  
    /* Construct BST */
    return sortedListToBSTRecur(&head, n); 
    }
    
TreeNode* sortedListToBSTRecur(ListNode **head_ref, int n) 
{ 
    /* Base Case */
    if (n <= 0) 
        return NULL; 
  
    /* Recursively construct the left subtree */
    TreeNode *left = sortedListToBSTRecur(head_ref, n/2); 
  
    /* Allocate memory for root, and link the above constructed left  
       subtree with root */
    TreeNode *root = new TreeNode((*head_ref)->val); 
    root->left = left; 
  
    /* Change head pointer of Linked List for parent recursive calls */
    *head_ref = (*head_ref)->next; 
  
    /* Recursively construct the right subtree and link it with root  
      The number of nodes in right subtree  is total nodes - nodes in  
      left subtree - 1 (for root) which is n-n/2-1*/
    root->right = sortedListToBSTRecur(head_ref, n-n/2-1); 
  
    return root; 
} 
    int countLNodes(ListNode *head) 
{ 
    int count = 0; 
    ListNode *temp = head; 
    while(temp) 
    { 
        temp = temp->next; 
        count++; 
    } 
    return count; 
} 
};
//fastest way++++++++++++++++++++++++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        for(ListNode *p = head; p != NULL; p = p->next) {
            ++len;
        }
        return dfs(head, len);
    }
    
    TreeNode *dfs(ListNode *&head, int len) {
        if(len == 0)
            return NULL;
        TreeNode *left = dfs(head, len / 2);
        TreeNode *res = new TreeNode(head->val);
        head = head->next;
        res->left = left;
        res->right = dfs(head, len - len / 2 - 1);
        return res;
    }
    
};
