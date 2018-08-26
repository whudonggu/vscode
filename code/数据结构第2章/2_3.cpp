//带头结点的单链表，从尾到头反向输出
struct LNode
{
    ElemType x;
    struct LNode *next;
}LNode,*Linklist;

//从头到尾循环时，每个节点以此入栈