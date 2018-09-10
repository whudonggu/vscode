#include<iostream>

using namespace std;

struct BTNode
{
    /* data */
    int val;
    BTNode* m_pleft;
    BTNode *m_pright;
    BTNode *m_parent;
    BTNode(int x):val(x),m_pleft(NULL),m_pright(NULL),m_parent(NULL){}
};

BTNode* getInorderSqueNext(BTNode* pNode)
{
    if(pNode==NULL)
        return NULL;

    BTNode *pNext = NULL;

    if(pNode->m_pright!=NULL)
    {
        BTNode *pRight = pNode->m_pright;
        while(pRight->m_pleft!=NULL)
            pRight = pRight->m_pleft;

        pNext = pRight;
    }

    else if (pNode->m_parent!=NULL)
    {
        BTNode* pcurrent = pNode;
        BTNode *parent = pNode->m_parent;
        
        while(parent!=NULL&&pcurrent==parent->m_pright){
            /* code */
            pcurrent = parent;
            parent = parent->m_parent;
        }
        pNext = parent;     //两种情况都找到了，当前节点为其父节点的左子节点和右子节点这两种情况
    }
    return pNext;
}

int main()
{
    BTNode *root = new BTNode(2);
    BTNode *t1 = new BTNode(1);
    BTNode *t2 = new BTNode(4);
    BTNode *t3 = new BTNode(5);
    BTNode *t4 = new BTNode(6);
    BTNode *t5 = new BTNode(7);
    BTNode *t6 = new BTNode(8);
    BTNode *t7 = new BTNode(9);
    root->m_pleft = t1;
    root->m_pright = t2;
    t2->m_pright = t3;
    t1->m_parent = root;
    t2->m_parent = root;
    t3->m_parent = t2;
    t1->m_pleft = t4;
    t4->m_parent = t1;
    t1->m_pright = t5;
    t5->m_parent = t1;
    t5->m_pleft = t6;
    t6->m_parent = t5;
    t5->m_pright = t7;
    t7->m_parent = t5;
    cout << getInorderSqueNext(t4)->val << '\n'
         << getInorderSqueNext(t1)->val << '\n'
         << getInorderSqueNext(t7)->val;
    return 0;
}