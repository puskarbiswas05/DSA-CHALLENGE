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
    TreeNode* deleteNode(TreeNode* root, int target) {
        if(root==NULL)
        return NULL;
        if(root->val>target){
            root->left=deleteNode(root->left,target);
            return root;
        }
        else if(root->val<target){
            root->right=deleteNode(root->right,target);
            return root;
        }
        else{
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->right==NULL){
                TreeNode *temp=root->left;
                delete root;
                return temp;
            }
            else if(root->left==NULL){
                TreeNode *temp=root->right;
                delete root;
                return temp;
            }
            else{
                //find greatest ele in left
                TreeNode *child=root->left;
                TreeNode *parent=root;
                //right most node
                while(child->right!=NULL){
                     parent=child;
                     child=child->right;
                }
                if(root!=parent){
                    parent->right=child->left;
                    child->left=root->left;
                    child->right=root->right;
                    delete root;
                    return child;
                }
                else{
                     child->right=root->right;
                     delete root;
                     return child;
                }
            }
            
        }

    }
};