#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

typedef struct
{   
    //数据域
    int *data;
    //当前长度
    int length;
}SqList;

Status InitList(SqList *L){
    //因为是直接按照地址访问的其data，所以可以不用解引用。
    L->data = (int *)malloc(MAXSIZE * sizeof(int));
    if(!L->data){
        return OVERFLOW;
    }
    L->length = 0;
    return OK;
}

Status ListInsert(SqList *L,int i,int e){
    //检查i的位置是否合法
    if(i < 1 || i > L->length + 1)
    {
        return ERROR;
    }

    //检查顺序表的储存空间是否已满
    if (L->length == MAXSIZE)
    {
        return ERROR;
    }


    //将插入位置后的元素依次向后移动
    for(int j = L->length - 1;j >= i - 1 ;j--){
        L->data[j + 1] = L->data[j];
    }

    //插入新元素
    L->data[i - 1] = e;
    L->length ++;

    return OK;
    
}

int GetElem(SqList *L,int i,int *e){
    //检查i的位置是否合法
    if(i<1 || i>L->length){
        return ERROR;
    }
    *e = L->data[i - 1];
    return OK;
}

Status LocateElem(SqList *L,int e){
    for(int i = 1;i <= L->length;i++){
        if(L->data[i - 1] == e){
            return i;
        }
    }
    return 0;
}

void MergList(SqList *A,SqList *B){
    int al = A->length;
    int bl = B->length;
    for(int i = 1;i < bl ; i++){
        int e = 0;
        GetElem(B,i,&e);
        if(!LocateElem(A,e))
        {
            ListInsert(A,al + 1,e);
        }
    }
}

void printList(SqList *L){
    for(int i = 1;i <= L->length;i++){
        printf("%d ",L->data[i - 1]);
    }
}

int main(){
    int A[4] = {7, 5, 3, 11};
    int B[3] = {2,6,3};

    int A_length = sizeof(A)/sizeof(A[0]);
    printf("A的长度为：%d\n",A_length);
    int B_length = sizeof(B)/sizeof(B[0]);
    printf("B的长度为：%d\n",B_length);

    SqList *LA = (SqList *)malloc(sizeof(SqList));
    SqList *LB = (SqList *)malloc(sizeof(SqList));

    if(InitList(LA) == OK)
    {
        printf("LA初始化完成\n");
    };
    if (InitList(LB) == OK)
    {
        printf("LB初始化完成\n");
    }

    for(int j = 1;j <= A_length;j++){
        ListInsert(LA,j,A[j-1]);
    }
    
    for(int j = 1;j <= B_length;j++){
        ListInsert(LB,j,B[j-1]);
    }
    printf("A的元素为：");
    printList(LA);
    printf("\n");
    printf("B的元素为：");
    printList(LB);
    printf("\n");
    printf("合并后的元素为：");
    MergList(LA,LB);
    printList(LA);
    printf("\n");
    
    free(LA->data);
    free(LB->data);
    free(LA);
    free(LB);


    return 0;
}