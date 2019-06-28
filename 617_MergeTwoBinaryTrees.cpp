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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        
        return t1;
    }
};
//myself
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* dummy; 
        if (t1) {
            if (t2){
                dummy = new TreeNode(t1->val + t2->val);
                dummy->left = mergeTrees(t1->left, t2->left);
                dummy->right = mergeTrees(t1->right, t2->right);
            } else {
                dummy = new TreeNode(t1->val);
                dummy->left = mergeTrees(t1->left, NULL);
                dummy->right = mergeTrees(t1->right, NULL);
            }
        } else if(t2){
            dummy = new TreeNode(t2->val);
            dummy->left = mergeTrees(NULL, t2->left);
            dummy->right = mergeTrees(NULL, t2->right);
        } else {
            return NULL;
        }
        return dummy;
    }
};