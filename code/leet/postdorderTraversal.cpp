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
    vector<int> postorderTraversal1(TreeNode *root) {
        if (root!=NULL) {
            postorderTraversal1(root->left);
            postorderTraversal1(root->right);
            //cout << root->val << '\n';
            res.push_back(root->val);
        }
            return res;
    }
    vector<int> postorderTraversal2(TreeNode *root){
        stack<BTNode*> s;
        vector<int> res2;
        BTNode *temp;
        TreeNode *p = root;
        while(p!=NULL||!s.empty())
        {
             while(p!=NULL)
            {
                BTNode *btn = (BTNode *)malloc(sizeof(BTNode));
                btn->node = p;
                btn->isFirst = true;
                s.push(btn);
                p = p->left;
            }
            if(!s.empty())
            {
               //BTNode *temp1 = (BTNode *)malloc(sizeof(BTNode));
                temp = s.top();
                s.pop();
                if(temp->isFirst==true)
                {
                    temp->isFirst = false;
                    s.push(temp);
                    p = temp->node->right;
                }
                else
                {
                    res2.push_back(temp->node->val);
                    p = NULL;
                }
                
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
    yb.postorderTraversal2(root);
    return 0;
}