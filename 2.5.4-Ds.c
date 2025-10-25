#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

//双向链表的储存结构
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;

}DuLNode,*DuLinkList;

//双向链表的插入
Status ListInsert_DuL(DuLinkList L,int i,ElemType e){

    DuLNode *p = L;
    int j = 0;
    while(p&&j<i-1)
    {
        p = p->next;
        ++j;
    }
    if(!p || j> i- 1||i<1){
        return ERROR;
    }

    DuLNode *s = (DuLNode *)malloc(sizeof(DuLNode));
    if(!s){
        return OVERFLOW;
    }

    s->data = e;

    s->next = p->next;
    if (p->next != NULL)
    {
        p->next->prior = s;
    }

    s->prior = p;
    p->next = s;
    return OK;
}

Status ListDelete_DuL(DuLinkList L,int i,ElemType *e)
{

   DuLNode *p = L->next;
   int j = 1;
   while (p && j<i)
   {
    p = p->next;
    ++j;
   }
   if (!p || j > i){
        return ERROR;
    }
   
   *e = p->data;

    p->prior->next = p->next;
    if (p->next != NULL)
    {
       p->next->prior = p->prior;
    }
    free(p);
    return OK;
}

int main(){


    return 0;
}