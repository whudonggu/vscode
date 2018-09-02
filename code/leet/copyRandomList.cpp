#include<iostream>
#include<map>


  //Definition for singly-linked list with a random pointer.
  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
 
class Solution {
public:
    RandomListNode *copyRandomList1(RandomListNode *head) {
        if(head==NULL)
            return NULL;
        RandomListNode *pnode = head;
        map<RandomListNode *, RandomListNode *> nomap;
        nomap.insert(pair<RandomListNode *, RandomListNode *>(NULL, NULL));
        RandomListNode *newhead = new RandomListNode(pnode->label);
        nomap.insert(pair<RandomListNode *, RandomListNode *>(pnode, newhead));
        RandomListNode *pnnode = newhead;

        
        while(*pnode->next!=NULL){
            pnnode->next = new RandomListNode(pnode->next->label);
            nomap.insert(pair<RandomListNode *, RandomListNode *>(pnode->next, pnnode->next));
            pnnode = pnnode->next;
            pnode = pnode->next;
        }

        pnnode = newhead;
        pnode = head;
        while(pnnode!=NULL)
        {
            pnnode->random = nomap.find(pnode->random)->second;
            pnnode = pnnode->next;
            pnode = pnode->next;
        }
        return newhead;
    }
    /*RandomListNode *copyRandomList2(RandomListNode *head)
    {
        if(head==NULL)
            return NULL;
        RandomListNode *pnode = head;
        RandomListNode *newhead = new RandomListNode(pnode->label);
        RandomListNode *pnnode = newhead;
        nomap.insert(pair<RandomListNode *, RandomListNode *>(pnode, pnnode));
        map<RandomListNode *, RandomListNode *> nomap;
        while(pnode!=NULL)
        {
            pnnode->next=
        }
        nomap.insert(pair<RandomListNode*,RandomListNode*>())
    }
    */
};