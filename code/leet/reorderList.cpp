#include<iostream>

//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head==NULL)
            return;
        ListNode *res = new ListNode(0);
        ListNode *p = head, *cur = res;
        int label = 1;
        while(p!=NULL)
        {
            ListNode *temp=p;
            ListNode *pretemp=NULL;
            if(label==0)
            {
                
                while(temp!=NULL&&temp->next!=NULL){
                    pretemp = temp;
                    temp = temp->next;
                }
                if(pretemp!=NULL)
                {
                    cur->next = temp;
                    cur = cur->next;
                    pretemp->next = NULL;
                    label = 1;
                    continue;
                }
                else
                {
                    cur->next = temp;
                    cur = cur->next;
                    //pretemp->next = NULL;
                    label = 1;
                    break;
                }
            }
            if(label==1)
            {
                cur->next = temp;
                cur = cur->next;
                label = 0;
            }
            p = p->next;
        }
        return ;
    }
};

int main()
{
    Solution yb;
    ListNode *head = new ListNode(1);
    ListNode *t1 = new ListNode(2);
    ListNode *t2 = new ListNode(3);
    ListNode *t3 = new ListNode(4);
    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    yb.reorderList(head);
    return 0;
}