//非递归算法求树的高度

int Btdepth(BiTree T)
{
    if(!T)
        return 0;
    int front = -1, rear = -1;
    int last = 0, level = 0;    //last指向当前最右节点，level记录当前节点所在层数
    Queue<BTNode> Q;
    
}