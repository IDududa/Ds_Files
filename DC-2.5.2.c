#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

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

LNode* LocateElem(LinkList L,ElemType e){
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

Status CreateList_H(LinkList *L,int n){

    *L = (LinkList)malloc(sizeof(LNode));
    if (*L == NULL)
    {
       return ERROR;
    }
    
    (*L)->next = NULL;

    for(int i = 0;i<n;i++){

        LNode *p = (LNode *)malloc(sizeof(LNode));

        if(p == NULL) return ERROR;

        scanf("%d",&(p->data));
        p->next = (*L)->next;
        (*L)->next = p;
    }
    return OK;

}

Status CreateList_T(LinkList *L,int n){

    *L = (LinkList)malloc(sizeof(LNode));
    if (*L == NULL){
        return ERROR;
    }
    (*L)->next = NULL;
    LinkList r = *L;

    for (int i = 0;i<n;i++){

        LNode *p = (LNode *)malloc(sizeof(LNode));
        if (p == NULL){
            return ERROR;
        }
        scanf("%d",&(p->data));

        p->next = NULL;
        r->next = p;
        r = p;

    }
    return OK;
}

void PrintList(LinkList L){
    LNode *p = L->next;
    while (p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    
}

void PrintMenu()
{
    printf("------------------顺序表操作菜单--------------------\n");
    printf("1.链表初始化\n");
    printf("2.链表取值\n");
    printf("3.链表查找\n");
    printf("4.链表删除\n");
    printf("5.链表前插入\n");
    printf("6.链表后插入\n");
    printf("7.打印链表\n");
    printf("0.退出程序\n");
    printf("--------------------------------------------------\n");
    printf("输入数字选择");
}

int main(){
    LinkList L;
    int choice = -1;
    while (choice != 0)
    {
        PrintMenu();
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:{
            if(InitList(&L) == OK){
                printf("链表初始化成功\n");
            }
            else{
                printf("链表初始化失败\n");
            }
            break;
        }
        case 2:{
            ElemType e;
            int j;
            printf("请输入要取值的位置");
            scanf("%d",&j);
            if (GetElem(L,j,&e))
            {
                printf("该位置的元素为:%d\n",e);
            }
            else{
                printf("该位置的元素不存在\n");
            }
            break;
        }
        case 3:{
            ElemType e;
            printf("请输入要查找的元素");
            scanf("%d",&e);
            LNode *p = LocateElem(L,e);
            if (p)
            {
                printf("该元素的位置为:%d\n",p->data);
            }
            else{
                printf("该元素不存在\n");
            }
            break;
        }
        case 4:{
            int i;
            printf("请输入要删除的位置");
            scanf("%d",&i);
            if (ListDelete(L,i) == OK)
            {
                printf("删除成功\n");
            }
            else{
                printf("删除失败\n");
            }
            break;
        }
        case 5:{
            int i;
            ElemType e;
            printf("请输入要插入的位置");
            scanf("%d",&i);
            printf("请输入要插入的元素");
            scanf("%d",&e);
            if (ListInsert(L,i,e) == OK)
            {
                printf("插入成功\n");
            }
            else{
                printf("插入失败\n");
            }
            break;
        }
        case 6:{
            int i;
            ElemType e;
            printf("请输入要插入的位置");
            scanf("%d",&i);
            printf("请输入要插入的元素");
            scanf("%d",&e);
            if (ListInsert(L,i,e) == OK)
            {
                printf("插入成功\n");
            }
            else{
                printf("插入失败\n");
            }
            break;
        }
        case 7:{
            PrintList(L);
            break;
        }
        
        case 0:{
            printf("程序已退出。感谢使用！\n");
            break;
        }
        default:
            break;
        }
    }
    


    return 0;
}