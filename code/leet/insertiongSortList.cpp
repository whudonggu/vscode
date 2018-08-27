#include<iomanip>
#include<iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode *head2,*p,*len,*cur,*precur;
        head2 = head->next;
        head->next = NULL;
        while (head2!=NULL)
        {
            p = head2;
            head2 = head2->next;
            cur = head;
            precur = NULL;
            while(cur!=NULL&&p->val>cur->val)   //不判断cur是否有后继会导致cur->next->val的值是个未知值
            {
                precur = cur;
                cur = cur->next;
            }
            if(precur==NULL)                  //插入到头结点之前，交换法，直接伪插入
            {
                int temp=head->val;
                p->next = head->next;
                head->next = p;
                head->val=p->val;
                p->val=temp;
            }
            else                            //插入到其他节点
            {
                p->next = precur->next;
                precur->next = p;
            }
            
        }
    return head;
    }
};

int main()
{
    Solution yb;
    ListNode *head = new ListNode(-1);
    ListNode *test1 = new ListNode(5);
    ListNode *test2= new ListNode(3);
    ListNode *test3 = new ListNode(4);
    ListNode *test4 = new ListNode(0);
    head->next = test1;
    test1->next = test2;
    test2->next = test3;
    test3->next = test4;
    yb.insertionSortList(head);
    for (int i = 0; i < 5;i++)
    {
        cout << head->val<<'\n';
        head = head->next;
    }
    int a;
    return 0;
}
