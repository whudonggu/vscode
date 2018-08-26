struct LNode
{
    ElemType x;
    struct LNode *next,*prior;
}DLNode,*DLinklist;

//判断循环双链表是否对称

int Symmetry(DLinklist L)
{
    DLNode *p = L->next, q = L->prior;
    while (p!=q&&p->next!=q)            //链表长度为奇数或者为偶数两种情况
    {
        if(p->data==q->data)
        {
            p = p->next;
            q = q->prior;
        }
        
        else
        {
            return 0;
        }
    }
    return 1;
}