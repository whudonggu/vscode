struct LNode
{
    ElemType x;
    struct LNode *next;
}LNode,*Linklist;

//将带头结点的单链表A拆分为两个单链表A和B，A含奇数位的元素，B含偶数位的元素，且相对位置不变

//设置访问序号变量，每访问一个节点自动加一
//尾插法建立不改变顺序

Linklist DisCreat_1(Linklist &A)
{
    i = 0;
    B = (Linklist)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A, *rb = B, p;

    p = A->next;        //保存A的后继
    A->next = NULL;

    while (p!=NULL)
    {
        i++;
        if (i%2==0)
        {
            rb->next = p;
            rb = p;
        }
        if (i%2==1)
        {
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}