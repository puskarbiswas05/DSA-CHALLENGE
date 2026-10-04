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
    vector<int> getAllElements(TreeNode* r1, TreeNode* r2) {
 
        vector<int>ans;
        stack<TreeNode*>s1,s2;
        while(r1!=NULL){
            s1.push(r1);
            r1=r1->left;
        }
        while(r2!=NULL){
            s2.push(r2);
            r2=r2->left;
        }
        while(s1.size()>0 && s2.size()>0){
            if(s1.top()->val==s2.top()->val){
                ans.push_back(s1.top()->val);
                r1=s1.top()->right;
                s1.pop();
                ans.push_back(s2.top()->val);
                r2=s2.top()->right;
                s2.pop();
                

            }
            else if(s1.top()->val > s2.top()->val){
                ans.push_back(s2.top()->val);
                r2=s2.top()->right;
                s2.pop();
            }
            else{
                ans.push_back(s1.top()->val);
                r1=s1.top()->right;
                s1.pop();
            }
            while(r1!=NULL){
            s1.push(r1);
            r1=r1->left;
        }
        while(r2!=NULL){
            s2.push(r2);
            r2=r2->left;
        }
        }
        while(s1.size()>0) {
            ans.push_back(s1.top()->val);
            r1 = s1.top()->right;
            s1.pop();

            while(r1 != NULL) {
                s1.push(r1);
                r1 = r1->left;
            }
        }
        while(s2.size()>0) {
            ans.push_back(s2.top()->val);
            r2 = s2.top()->right;
            s2.pop();

            while(r2 != NULL) {
                s2.push(r2);
                r2 = r2->left;
            }
        }
        return ans;
        
        
    
    }
};