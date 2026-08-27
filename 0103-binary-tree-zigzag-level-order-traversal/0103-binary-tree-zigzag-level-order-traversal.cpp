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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*>s1;  //ltoR
        stack<TreeNode*>s2; 
       vector<vector<int>>ans; //RtoL
        if(root==NULL)
        return ans;
        
        s1.push(root);
        //vector<vector<int>>ans;
        while(s1.size()>0 || s2.size()>0){
            
            
           if(s1.size()>0){
             vector<int>level1;
                while(s1.size()>0){
                    TreeNode *temp=s1.top();
                    s1.pop();
                    level1.push_back(temp->val);
                    if(temp->left!=NULL){
                        s2.push(temp->left);
                    }
                    if(temp->right!=NULL){
                        s2.push(temp->right);
                    }
                }
                 ans.push_back(level1);
             }
            
             
             if(s2.size()>0){
                 vector<int>level2;
                while(s2.size()>0){
                    TreeNode *temp=s2.top();
                    s2.pop();
                    level2.push_back(temp->val);
                    if(temp->right!=NULL){
                        s1.push(temp->right);
                    }
                    if(temp->left!=NULL){
                        s1.push(temp->left);
                    }
                }
                ans.push_back(level2);
             }
            
        }
        return ans;
    }
};