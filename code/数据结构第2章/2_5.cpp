//O(1)空间就地逆置单链表
struct LNode
{
    ElemType x;
    struct LNode *next;
}LNode,*Linklist;

//摘下头结点后，依次头插法插入每个节点
Linklist Reserse_1(Linklist L)
{
    LNode *p, *r;
    p = L - next;
    L - next = NULL;
    while(p!=NULL)
    {
        r = p->next;            //暂存p的后继
        p->next = L - next;
        L->next = p;
        p = r;
    }
    return L;
}