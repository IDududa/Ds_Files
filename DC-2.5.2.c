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


//因为*L是解引用，所以在main中会传入一个变量，我们操作时就是对这个变量进行操作码？
Status InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(LNode));

    if (*L = NULL){
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}



int main(){



    return 0;
}