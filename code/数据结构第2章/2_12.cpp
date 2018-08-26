struct LNode
{
    ElemType x;
    struct LNode *next;
}LNode,*Linklist;

//去掉递增有序单链表中数值相同的元素，使不再含有相同元素

void Del_Same(Linklist &L)
{
    LNode *p = L->next, *q;
    while (p->next!=NULL)
    {
        q = p->next;
        if (p->data==q->data)
        {
            p->next = q->next;
            free(q);
        }
        else
            p = p->next;
    }
}