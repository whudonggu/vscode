#include<iostream>
//Definition for singly-linked list.
struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int length=0;
        while(head->next!=NULL)
            length++;
        if(length==0)
            return NULL;
        ListNode temp = new ListNode(0);
        temp = head;
        int interval = 1;
        for (; interval < length;interval=2*interval)
        {
            ListNode *pre = temp;  //每次倍增interval时，pre重置为表头；
            ListNode *first = pre->next;
            ListNode *second = pre->next;

            //相邻两个子表归并
            while(first!=NULL&&second!=NULL)
            {
                //将second移至第二段子表起始处
                int i = 0;
                while(i<interval&&second!=NULL)     //second！=NULL是为了不溢出链表
                {
                    second = second->next;
                    i++;
                }
                int fvisit = 0, svisit = 0;      //存储相邻两个子表的访问次数
                
                while(fvisit<interval&&svisit<interval&&first!=NULL&&second!=NULL){
                    //判断数值大小后采用尾插法不改变大小次序，且pre一直在向链表尾移动
                    if (first->val<second->val) {
                        pre->next = first;
                        pre = first;
                        first = first->next;
                        fvisit++;
                    }
                    else
                    {
                        pre->next = second;
                        pre = second;
                        second = second->next;
                        svisit++;
                    }
                }
                    while(fvisit<interval&&first!=NULL)     //这里两个while将first与second均推向下两个子表的起始处
                    {
                        pre->next = first;
                        pre = first;
                        first = first->next;
                        fvisit++;
                    }
                    while (svisit<interval&&second!=NULL)
                    {
                        pre->next = second;
                        pre = second;
                        second = second->next;
                        svisit++;
                    }
            }
            pre->next = second;
            first = second;
        }
        ListNode *res->next = temp;
        delete temp;
        temp == NULL;
        return res;
    }
};