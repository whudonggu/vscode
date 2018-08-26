struct LNode
{
    ElemType x;
    struct LNode *next;
}LNode,*Linklist;

void Min_Delete(Linklist &head)
{
    while (head->next!=NULL)
    {
        pre = head;
        p = pre->next;
        while (p->next!=NULL)
        {
            if (p->next->data<pre->next->data)
                pre = p;
            p = p - next;
        }
        print(pre->next->data);
        LNode u = pre->next;
        pre->next = u->next;
        free(u);
    }
    free(head);
}