struct LNode
{
    ElemType x;
    struct LNode *next;
}LNode,*Linklist;
void Del_X_3(Linklist &L,ElemType x)
{
    LNode *p;
    if(L==NULL)
        return;
    if(L->data==x)
    {
        p = L;
        L = L->next;
        free(p);
        Del_X_3(L, x);
    }
    
    else
    {
        Del_X_3(L->next, x);
    }    
}