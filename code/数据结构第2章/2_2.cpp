struct LNode
{
    ElemType x;
    struct LNode *next;
}LNode,*Linklist;

void Del_X_1(Linklist &L,ElemType x)
{
    LNode *p = L->next, *pre = L, *q;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            q = p;      //保存删除节点
            p = p->next;
            pre->next = p;
            free(q);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

void Del_X_2(Linklist &L, ElemType x)
{
    LNode *p = L->next, *r = L, *q;
    while(p!=NULL)
    {
        if(p->data!=x)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        
        else
        {
            q = p;
            p = p->next;
            free(q);
        }
    }
    r->next = NULL;
}