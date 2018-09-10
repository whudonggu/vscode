#include<iostream>

using namespace std;

class Solution{
public:
    void replaceBlank(char string[],int length)     //length为传入数组的总容量
    {
        if(string==NULL||length<=0)
            return;

        int originallen = 0,blank=0;

        for (int i = 0; string[i]!='\0'; i++)
        {
            originallen++;
            if(string[i]==' ')
                blank++;
        }

        int newlen = originallen + 2 * blank;

        if(newlen>length)
            return;     //如果长度超过容量，返回

        int indexofOld=originallen - 1, indexofNew = newlen - 1;

        while (indexofOld>=0&&indexofNew>indexofOld)
        {
            if(string[indexofOld]==' ')
                {
                    string[indexofNew--] = '0';
                    string[indexofNew--] = '2';
                    string[indexofNew--] = '%';
                }
            else  
                {
                    string[indexofNew--] = string[indexofOld];
                }
                --indexofOld;
        }

    }
};

int main()
{
    Solution yb;
    char test[50] = "wear  ehappy.";
    //test = nullptr;
    yb.replaceBlank(test, 50);
    return 0;
}