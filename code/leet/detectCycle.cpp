#include<iostream>

//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode *pslow = head;
        ListNode *pfast = head;
        int countCycle = MeetingNode(head);
        if(countCycle!=0)
        {
            while(countCycle)
            {
                pfast = pfast->next;
                countCycle--;
            }
            while(pfast!=pslow)
            {
                pfast = pfast->next;
                pslow = pslow->next;
            }
            return pslow;
        }
        return NULL;
    }
    int MeetingNode(ListNode *head)
    {
        ListNode *pslow = head;
        if(pslow->next==NULL)
            return 0;
        ListNode *pfast = pslow->next;
        while (pfast != NULL && pslow!=NULL)
        {
            if(pfast==pslow)
            {
                ListNode *temp = pfast;
                pfast = pfast->next;
                int res = 1;
                while(pfast!=temp)
                {
                    res++;
                    pfast = pfast->next;
                }
                return res;
            }
            pfast = pfast->next;
            pslow = pslow->next;
            if(pfast!=NULL)
                pfast = pfast->next;
        }
        return 0;
    }
};

int main()
{
    Solution yb;
    ListNode *head = new ListNode(1);
    ListNode *t1 = new ListNode(2);
    ListNode *t2 = new ListNode(3);
    ListNode *t3 = new ListNode(4);
    ListNode *t4 = new ListNode(5);
    ListNode *t5 = new ListNode(6);
    head->next = t1;
    //t1->next = t2;
    //t2->next = t3;
    //t3->next = t4;
    //t4->next = t5;
    //t5->next = t3;

    yb.detectCycle(head);
    return 0;
}  