#include<iostream>
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        
        if (root!=NULL) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            res.push_back(root->val);
        }
        int a=0;
        return res;
    }
};