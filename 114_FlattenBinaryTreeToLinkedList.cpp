//self-wirte
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
    void flatten(TreeNode* root) {
        //check if root is null
        if (root == NULL || root->left == NULL && root->right == NULL) return;
        flatten (root->left);
        //store the original right branch node
        TreeNode* right = root->right;
        //move the left node to the root->right
        root->right = root->left;
        root->left = NULL;
        //find the tail of the new right branch and add the original right branch to the tail
        TreeNode* curr = root; 
        while(curr->right) curr = curr->right;
        curr->right = right;
        // flat the right side of the branch, treat it as a new root of a binary tree
        flatten(right);
        return;            
    }
};
//From geeksforgeeks
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
    void flatten(TreeNode* root) {
        // base condition- return if root is NULL 
    // or if it is a leaf node 
    if (root == NULL || root->left == NULL && 
                        root->right == NULL) { 
        return; 
    } 
  
    // if root->left exists then we have  
    // to make it root->right 
    if (root->left != NULL) { 
  
        // move left recursively 
        flatten(root->left); 
     
        // store the node root->right 
        TreeNode* tmpRight = root->right; 
        root->right = root->left; 
        root->left = NULL; 
  
        // find the position to insert 
        // the stored value    
        TreeNode* t = root->right; 
        while (t->right != NULL) { 
            t = t->right; 
        } 
  
        // insert the stored value 
        t->right = tmpRight; 
    } 
  
    // now call the same function 
    // for root->right 
    flatten(root->right); 
    return; 
} 
};
//Need to use Stack (extra space)
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
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        stack<TreeNode*> my_stack;
        my_stack.push(root);
        TreeNode dummy(0);
        TreeNode* node = &dummy;
        while(!my_stack.empty()) {
            node->right = my_stack.top();
            node->left = nullptr;
            node = node->right;
            my_stack.pop();
            if(node->right != nullptr) my_stack.push(node->right);
            if(node->left != nullptr) my_stack.push(node->left);
        }
        return;
    }
};