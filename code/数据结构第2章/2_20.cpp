struct LNode
{
    int freq;
    ElemType x;
    struct LNode *next,*prior;
}DNode,*DLinklist;


DLinklist Locate(DLinklist &L,ElemType x){
    DNode *p = L->next, *q;
    while(p&&p->data!=x)
        p = p->next;
    if(!p)
        {
            printf("不存在值为x的节点\n");
            exet(0);
        }
    else
    {
        p->freq++;
        p->next->prior = p->prior;
        p->prior->next = p->next;
        q = p->prior;
        while(q!=L&&q->freq<=p->freq)
            q = q->prior;
        p->next = q->next;
        q->next->prior = p;
        p->prior = q;
        q->next = p;
    }
    return p;
}
