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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            ans.push_back(q.front()->val);
            int n=q.size();
            while(n>0){
                TreeNode *temp=q.front();
                q.pop();
                if(temp->right!=NULL)
                q.push(temp->right);
                if(temp->left!=NULL)
                q.push(temp->left);
                n--;
                
            }
        }
        return ans;
    }
};