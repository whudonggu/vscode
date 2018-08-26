//非递归后序遍历二叉树

void PostOrder(BinTree *root)
{
    stack<BTNode *> s;
    BinTree *p = root;
    BTNode *temp;
    while(p!=NULL||!s.empty())
    {
        while (p!=NULL)                     //找到最左子节点
        {
            BTNode *btn = (BTNode *)malloc(sizeof(BTNode));
            btn->btnode = p;
            btn->isFirst = true;
            s.push(btn);
            p = p->lchild;
        }
        if(!s.empty())
        {
            temp = s.top();
            s.pop();
            if(temp->isFirst==true)         //第一次出现在栈顶
            {
                temp->isFirst = false;
                s.push(temp);
                p = temp->btnode->rchild;
            }
            
            else                            //第二次出现在栈顶
            {
                cout << temp->btnode->data << " ";
                p = NULL;
            }
            
        }
    }
}