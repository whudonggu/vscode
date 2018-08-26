struct LNode
{
    ElemType x;
    struct LNode *next;
}LNode,*Linklist;

Linklist Search_lst_Common(Linklist L1,Linklist L2)
{
    int len1 = Length(L1), len2 = Length(L2),dist;
    Linklist longList, shortList;
    if(len1>len2)
    {
        longList = L1->next;
        shortList = L2->next;
        dist = len1 - len2;
    }
    
    else
    {
        longList = L2->next;
        shortList = L1->next;
        dist = len2 - len1;
    }

    while(dist--)
    {
        longList = longList->next;
    }
    while(longList!=NULL)
    {
        if(longList==shortList)
            return longList;
        else
        {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}