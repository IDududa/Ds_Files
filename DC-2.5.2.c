#include <stdio.h>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;

typedef struct LNode
{
   ElemType data;
   struct LNode *next;
}LNode,*LinkList;


Status InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(LNode));

    if (*L = NULL){
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}

Status GetElem(LinkList L,int i,ElemType *e){
    int j = 1;
    LNode *p  = L->next;
    while (p && j<i)
    {
       p = p->next;
       ++j;
    }
    if (!p || j != i){
        return ERROR;
    }
    *e = p->data;
    return OK;

}

Status LocateElem(LinkList L,ElemType e){
    LNode *p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    
    return p;

}

int main(){



    return 0;
}