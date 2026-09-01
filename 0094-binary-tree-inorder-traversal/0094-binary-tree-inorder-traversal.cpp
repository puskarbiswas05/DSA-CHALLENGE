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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
        return ans;
        stack<TreeNode*>s;
        stack<bool>visited;
        s.push(root);
        visited.push(0);
        while(s.size()>0){
            TreeNode *temp=s.top();
            s.pop();
            int flag=visited.top();
            visited.pop();
            if(flag==0){
                if(temp->right!=NULL){
                s.push(temp->right);
                visited.push(0);
                }
                s.push(temp);
                visited.push(1);
                 if(temp->left!=NULL){
                s.push(temp->left);
                visited.push(0);
            }
            }
            else{
                ans.push_back(temp->val);
            }

            }
        return ans;

    }
};