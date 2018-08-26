#include<iostream>


class Solution {
public:
    int run(TreeNode *root) {
        if(root==NULL)
            return 0;
        else if(root->left==NULL&&root->right==NULL)
            return 1;
        else if (root->left!=NULL&&root->right==NULL)
        {
            return run(root->left) + 1;
        }
        else if (root->left==NULL&&root->right!=NULL)
        {
            return run(root->right) + 1;
        }
        else
        {
            int left_min = run(root->left);
            int right_min = run(root->right);
            return (left_min > right_min ? right_min : left_min) + 1;
        }
    }
};