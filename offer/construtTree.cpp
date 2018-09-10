#include<iostream>

using namespace std;


struct BTNode
{
    /* data */
    int val;
    BTNode* m_pleft;
    BTNode *m_pright;
    BTNode(int x):val(x),m_pleft(NULL),m_pright(NULL){}
};

BTNode* constructCore(int* startpreorder,int* endpreorder,int* startinorder,int* endinorder)
{
    int rootvalue = *startpreorder;
    BTNode *root = new BTNode(rootvalue);
    root->m_pleft = root->m_pright = NULL;

    if(startpreorder==endpreorder)      //递归到只有一个节点时
    {
        if(*startpreorder==*startinorder)
            return root;
        else
        {
            //throw std::exception("Invalid input.");
        }
    }

    //在中序序列中找根节点的位置
    int* rootinorder = startinorder;     //指针
    
    while(rootinorder<=endinorder&&*rootinorder!=rootvalue){
        /* code */
        ++rootinorder;
    }
    
    //if(rootinorder==endinorder&&*rootinorder!=rootvalue)
        //throw std::exception("Invalid input.");
    //int left_length;
    int left_length = rootinorder - startinorder;
    int* left_preorderend = startpreorder + left_length;

    if(left_length>0)
    {
        root->m_pleft = constructCore(startpreorder + 1, left_preorderend, startinorder, rootinorder - 1);

    }

    if(left_length<endpreorder-startpreorder)
    {
        root->m_pright = constructCore(left_preorderend + 1, endpreorder, rootinorder + 1, endinorder);
    }

    return root;
}


BTNode *construct(int *preorder,int* inorder,int length)
{
    if(preorder==NULL||inorder==NULL||length<=0)
        return NULL;
    return constructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}



int main()
{
    int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};
    BTNode *T = construct(preorder, inorder, 8);
    return 0;
}
