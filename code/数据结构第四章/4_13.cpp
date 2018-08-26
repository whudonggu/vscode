#include <stack>
typedef struct{
    BitNode t;
    int tag;        //tag=0表示左子女已被访问，tag=1表示右子女已被访问
} sstack;

stack<sstack> s1, s2;

BitTree Ancestor(BitTree root,BiTNode *p,BiTNode *q)
{
    BiTNode *bt = root;
    list<BiTNode> b1, b2;
    b1 = Ancestor_X(root, p);
    b2 = Ancestor_X(root, q);
    //p的祖先均保存在b1中，q的祖先均保存在b2中，那么b1与b2的前面所有节点一定相同，
    for (int i = 0, j = 0; b1.i == b2.j;i++,j++)
        ;
    //那么b1.i即为最近公共祖先
}

list<BitNode> Ancestor_X(BitTree *root,BitNode *p)
{
    BiTNode *bt = root;
    list<BiTNode> b1;
    while (bt!=NULL||!s.empty())
    {
        while (bt!=NULL&&bt!=p&&bt!=q)
            while (bt!=NUll)
            {
                sstack temp;
                temp.t = bt;
                temp.tag = 0;
                s1.push(temp);
                bt = bt->lchild;
            }
        if(!s1.empty())
        {   
            sstack *temp = s1.top();
            s1.pop();
            if(temp->tag==0)
            {
                temp->tag = 1;
                s1.push(temp);
                p = temp->BiTNode->rchlid;
            }
            else
            {
                b1.push(temp->BitNode);
                p = NULL;
            }
        }
    }
    return b1;
}