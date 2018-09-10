#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;
// Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




class Solution {
public:
    vector<int> inorderTraversal1(TreeNode *root) {
        if(root!=NULL)
        {
            inorderTraversal1(root->left);
            res1.push_back(root->val);
            inorderTraversal2(root->right);
        }
        return res1;
    }
    vector<int> inorderTraversal2(TreeNode *root){
        vector<int> res2;
        stack<TreeNode *> s;
        TreeNode *p=root;
        while(p!=NULL||!s.empty())
        {
            while(p!=NULL)
            {
                s.push(p);
                p = p->left;
            }
            if(!s.empty())
            {
                p = s.top();
                res2.push_back(p->val);
                s.pop();
                p = p->right;
            }
        }
        return res2;
    }
    private:
      vector<int> res1;
};

int main()
{
    //int *mm = nullptr;
    Solution yb;
    TreeNode *root = new TreeNode(2);
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(5);
    TreeNode *t4 = new TreeNode(6);
    TreeNode *t5 = new TreeNode(7);
    root->left = t1;
    root->right = t2;
    t2->right = t3;
    t1->right = t4;
    t4->left = t5;
    //yb.inorderTraversal1(root);
    yb.inorderTraversal2(root);
    return 0;
}