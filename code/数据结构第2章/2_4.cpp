//删除最小值节点
//1.最小值唯一
struct LNode
{
    ElemType x;
    struct LNode *next;
}LNode,*Linklist;


Linklist Delete_Min(Linklist &L)
{
    LNode *pre = L,*p = pre->next;
    LNode *minpre = pre, *minp = p;
    while(p!=NULL)
    {
        if(p->data<minp->data)
        {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
    return L;
}