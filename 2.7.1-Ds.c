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
    if(i >= 1 && i <= L->length + 1)
    {
        return ERROR;
    }

    //检查顺序表的储存空间是否已满
    if (L->length == MAXSIZE)
    {
        return ERROR;
    }


    //将插入位置后的元素依次向后移动
    for(int j = L->length - 1;j >= 1;j--){
        L->data[j + 1] = L->data[j];
    }

    //插入新元素
    L->data[i - 1] = e;
    L->length ++;

    return OK;
    
}

int main(){
    int A[10] = {7, 5, 3, 11};
    int B[10] = {2,6,3};

    int A_length = sizeof(A)/sizeof(A[0]);
    int B_length = sizeof(B)/sizeof(B[0]);

    SqList *LA;
    SqList *LB;

    if(InitList(LA) != NULL)
    {
        printf("LA初始化完成\n");
    };
    if (InitList(LB) != NULL)
    {
        printf("LB初始化完成\n");
    }

    for(int j = 1;j <= A_length;j++){
        ListInsert(LA,j,A[j-1]);
        printf("插入成功\n");
    }
    
    for(int j = 1;j <= A_length;j++){
        ListInsert(LB,j,B[j-1]);
        printf("插入成功\n");
    }
    



    return 0;
}