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


struct BTNode
{
    bool isFirst;
    TreeNode *node;
};

class Solution {
public:
    vector<int> preorderTraversal1(TreeNode *root) {
        if(root!=NULL)
        {
            res.push_back(root->val);
            preorderTraversal1(root->left);
            preorderTraversal1(root->right);
        }
        return res;
    }
    vector<int> preorderTraversal2(TreeNode *root){
        vector<int> res2;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while(p!=NULL||!s.empty())
        {
            while(p!=NULL)
            {
                res2.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            if(!s.empty())
            {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return res2;
    }
private:
  vector<int> res;
};


int main()
{
    Solution yb;
    TreeNode *root = new TreeNode(2);
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(5);
    root->left = t1;
    root->right = t2;
    t2->right = t3;
    yb.preorderTraversal2(root);
    return 0;
}