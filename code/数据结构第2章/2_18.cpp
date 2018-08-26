struct LNode
{
    ElemType x;
    struct LNode *next,*prior;
}LNode,*Linklist;

//有两个循环单链表，将h2连接到h1之后，仍保持循环格式

LinkList Link(LinkList &h1,Linklist &h2 )
{
    LNode *P, *q;
    p = h1;
    while (p->next!=h1)
    {
        p = p->next;
    }
    q = h2;
    while(q->next!=h2)
        q = q->next;
    p->next = h2;
    q->next = h1;
    return h1;
}