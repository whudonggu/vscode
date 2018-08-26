//二叉链表方式存储二叉树，求非空二叉树b的宽度（既具有节点数最多那一层的节点个数）

typedef struct{
    BiTNode node;       //树节点
    int level;          //节点层次
} Qu;

int BTWidth(BiTree *root)
{
    int parentSize = 1, childSize = 0,max=1;
    BiTNode *temp;
    queue<BiTNode*> q;
    q.push(root);
    while(!q.empty)
    {
        temp = q.front();
        q.pop();

        if(temp->lchild!=NULL)
        {
            q.push(temp->lchild);
            childSize++;
        }
        if (temp->rchild!=NULL)
        {
            q.push(temp->rchild);
            childSize++;
        }
        if(childSize>max)
            max = childSize;
        parentSize--;
        if(parentSize==0)
        {
            parentSize = childSize;
            childSize = 0;
        }
    }
}