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

    if (*L == NULL){
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

Status ListInsert(LinkList L,int i,ElemType e){
    LNode *p = L;
    int j = 0;
    while (p && (j<i-1))
    {
       p = p->next;
       ++j;
    }
    if(!p || j>i-1){
        return ERROR;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList L,int i){
    LNode *p = L;
    int j = 0;
    while((p->next) && j<i-1){
        p = p->next;
        ++j;
    }
    if(!(p->next) ||j >i-1){
        return ERROR;
    }
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}

void CreateList_H(LinkList *L,int n){

    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;

    for(int i = 0;i<n;i++){

        LNode *p = (LNode *)malloc(sizeof(LNode));

        if(p == NULL) return OVERFLOW;

        scanf("%d",&(p->data));
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateList_T(LinkList *L,int n){
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    LinkList r = *L;
    for (int i = 0;i<n;i++){
        LNode *p = (LNode *)malloc(sizeof(LNode));
        scanf("%d",&(p->data));
        p->next = NULL;
        r->next = p;
        r = p;
    }

}



int main(){



    return 0;
}