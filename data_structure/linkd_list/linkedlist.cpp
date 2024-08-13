#include <stdio.h>
#include <stdlib.h>

struct n
{
    int x;
    n * next;
};
typedef n node;
int main()
{
    node *root;
    root = (node *) malloc(sizeof(node));
    root -> x = 10;
    root->next = (node *) malloc(sizeof(node));
    root ->next->x=20;
    root->next->next= (node *) malloc(sizeof(node));
    root->next->next->x=30;

    node *iter;
    iter = root;
    printf("%d\n",iter->x);
    iter = iter->next;
    printf("%d\n",iter->x);

    printf("*************\n");

    iter = root;
    int i=0;

    while(iter-> next != NULL)
    {
        i++;
        printf(" %d. eleman = %d\n",i,iter->x);
        iter=iter->next;
    }
    printf("ekleme yapacağımız yer\n");
    for(i=3;i<8;i++)
    {
        iter->next=(node *)malloc(sizeof(node));
        iter=iter->next;
        iter->x =i*10;
        printf("%d ",iter->x);
        iter->next=NULL;
    }


}