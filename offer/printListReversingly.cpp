#include<iostream>
#include<stack>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
    ListNode(int x):m_nValue(x),m_pNext(NULL){}
};

void printListReversingly_Iteratively(ListNode* pHead)
{
    stack<ListNode *> nodes;
    
    //保存头结点
    ListNode *pNode = pHead;
    while(pNode!=NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while (!nodes.empty())
    {
        pNode = nodes.top();
        cout << pNode->m_nValue << '\t';
        nodes.pop();
    }
}

void printListReversingly_Recursively(ListNode* pHead)
{
    if(pHead!=NULL)
    {
        if (pHead->m_pNext!=NULL)
        {
            printListReversingly_Recursively(pHead->m_pNext);
        }
        cout << pHead->m_nValue << '\t';
    }
}

int main()
{
    ListNode *test = new ListNode(22);
    ListNode *head = new ListNode(1);
    ListNode *t1 = new ListNode(2);
    ListNode *t2 = new ListNode(3);
    ListNode *t3 = new ListNode(4);
    head->m_pNext = t1;
    t1->m_pNext = t2;
    t2->m_pNext = t3;
    cout << &head << ' ' << &*head << '\n';
    int m = 1;
    int *n = &m;
    cout << &n << ' ' << &*n << ' ' << &m<<' '<<*n;
    printListReversingly_Iteratively(head);
    printListReversingly_Recursively(head);
    return 0;
}
