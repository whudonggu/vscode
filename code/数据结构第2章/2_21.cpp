struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*Linklist;

//倒数第k个节点

int Search_k(Linklist L,int k)
{
    LNode *p = L->next, *q = L->next;
    int count = 0;
    while(p!=NULL)
    {
        if(count<k)
            count++;
        else
            q = q - next;
        p = p->next;
    }
    if(count<k)
        return 0;
    else
    {
        printf("%d", q->data);
        return 1;
    }
}