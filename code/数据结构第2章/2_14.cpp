struct LNode
{
    ElemType x;
    struct LNode *next;
}LNode,*Linklist;

//从A和B中的重复元素建一个新的单链表C，不破坏A和B的结构

void MergeList(Linklist &La,Linklist &Lb)
{
    LNode *r, *ra = La->next, *rb = Lb->next;
    Lc = (Linklist)malloc(sizeof(LNode));
    Lc->next = NULL;

    while (pa&&pb)
    {
        if (pa->data<=pb->data)
        {
            r = pa->next;
            pa->next = Lc->next;
            Lc->next = pa;
            pa = r;
        }
        
        else
        {
            r = pb->next;
            pb->next = Lc->next;
            Lc->next = pb;
            pb = r;
        }

    }
    if(pa)
        pb = pa;
    
    while (pb)
    {
        r = pb->next;
        pb->next = Lc->next;
        Lc->next = pb;
        pb = r;
    }
    free(La);
    free(Lb);
}