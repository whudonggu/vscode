struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*Linklist;

void func(LNode h,int n){
    LNode p = h, r;
    int *q, m;
    q = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n + 1;i++)
    {
        *(q + 1) = 0;
    }
    while(p->next!=NULL)
    {
        m = p->next->data > 0 ? p->next->data > 0 : -p->next->data > 0;
        if(*(q+m)==0)
        {
            *(q + m) = 1;
            p = p->next;
        }
        else
        {
            r = p->next;
            p->next = r->next;
            free(r);
        }
    }
    free(q);
}