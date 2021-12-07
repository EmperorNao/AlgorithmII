/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        
        if (not subroot and not root) {

            return true;

        }
        if (not root and subroot) {

            return false;

        }
        return traversal(root, subroot);

        
    }

    bool traversal(TreeNode* root, TreeNode* subroot) {

        if (root != nullptr) {

            if (root->val == subroot->val) {

                if (symmetric(root, subroot)) {

                    return true;

                }

            }
            return traversal(root->left, subroot) or traversal(root->right, subroot);

        }
        return false;


    }

    
    bool symmetric(TreeNode* root, TreeNode* subroot) {
        
        if (root xor subroot) {
            
            return false;
            
        }
        if (not root and not subroot) {
            
            return true;
            
        }
        if (root->val != subroot->val) {
            
            return false;
            
        }
        
        return symmetric(root->left, subroot->left) and symmetric(root->right, subroot->right);  
        
    }
    
};