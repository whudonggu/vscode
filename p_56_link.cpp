#include<iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
    ListNode(int x):m_nValue(x),m_pNext(NULL){}
};

void AddToTail(ListNode** pHead,int value)
{
    ListNode *pNew = new ListNode(value);
    
    if(*pHead==NULL)
        *pHead = pNew;
    else
    {
        ListNode *pNode = *pHead;

        while(pNode->m_pNext!=NULL)
            pNode = pNode->m_pNext;

        pNode->m_pNext = pNew;
    }
}