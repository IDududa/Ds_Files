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
   char no[20];
   char name[50];
   float price;
}Book;

typedef struct 
{
    Book *elem;
    int length;
}SqList;

//初始化顺序表
Status InitList(SqList *L){

    L->elem = (Book*)malloc(MAXSIZE *sizeof(Book));
    if(!L->elem){
        exit(OVERFLOW);
        }
    L->length = 0;
    return OK;
    }

//获取顺序表中某一元素的值
Status GetElem(SqList L,int i,Book *e){
    if(i < 1 || i > L.length)
    {
        return ERROR;
    }

    *e = L.elem[i-1];
    return OK;

}

//查找顺序表中的某一元素
Status LocateElem(SqList L,char *e)
{
    for(int i = 0;i< L.length;i++)
    {
        if(strcmp(L.elem[i].no,e) == 0)
        {
            return i+1;
        }
    }

    return ERROR;
}

//往顺序表中插入元素
Status ListInsert(SqList *L,int i,Book e)
{
    if (i < 1 || i > L->length+1)
    {
        return ERROR;
    }
    if (L->length == MAXSIZE)
    {
         return ERROR;
    }

    for (int j = L->length - 1; j >= i - 1; j--) {
        L->elem[j + 1] = L->elem[j];
    }

    L->elem[i - 1] = e;
    L->length++;

    return OK;
}

Status ListDelete(SqList *L,int i,Book *e)
{

    if (L->length == 0) {
        return ERROR; 
    }

    if (i < 1 || i > L->length)
    {
        return ERROR;
    }
    
    *e = L->elem[i - 1];

    for(int j = i;j<=L->length-1;j++)
    {
        L->elem[j-1] = L->elem[j];
    }
    L->length --; 
    return OK;
}

// 遍历并打印顺序表中的所有元素
void PrintList(SqList L) {
    printf("------ 当前顺序表内容 ------\n");
    printf("当前长度: %d\n", L.length);
    printf("位置\t图书编号\t\t书名\t\t价格\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < L.length; i++) {
        printf("%d\t%s\t\t%s\t\t%.2f\n", 
               i + 1, 
               L.elem[i].no, 
               L.elem[i].name, 
               L.elem[i].price);
    }
    printf("--------------------------------------------------\n\n");
}
// 打印出主页面
void PrintMenu()
{
    printf("------------------顺序表操作菜单--------------------\n");
    printf("1.顺序表初始化\n");
    printf("2.顺序表取值\n");
    printf("3.顺序表查找\n");
    printf("4.顺序表插入\n");
    printf("5.顺序表删除\n");
    printf("6.打印顺序表\n");
    printf("0.退出程序\n");
    printf("--------------------------------------------------\n");
    printf("输入数字选择");
}

int main(){
    SqList myList;
    int choice = -1;
    int isIniitialized = 0;

    while (choice != 0)
    {
        PrintMenu();
        scanf("%d",&choice);
        getchar();
        if(choice >= 2 && choice <= 6 && !isIniitialized)
        {
            printf("[失败]顺序表未初始化，请先执行1顺序表初始化操作。\n");
            continue;
        }
        switch (choice)
        {
        case 1:{
            if (InitList(&myList) == OK)
            {
                isIniitialized = 1;
                printf("[成功]顺序表初始化成功。\n");
            }else{
                printf("[失败]顺序表初始化失败。\n");
            }
            
            break;}
        
        case 2:{
            int i;
            Book e;
            printf("请输入要获取的元素的位置:");
            scanf("%d",&i);
            getchar();

            if (GetElem(myList,i,&e) == OK)
            {
                printf("[成功] 第%d个位置的元素是: \n",i);
                printf("图书编号为: %s,书名: %s,价格: %.2f \n",e.no,e.name,e.price);
            }else{
                printf("[失败] 位置%d无效或超出范围 \n");
            }
            break;
        }
        
        case 3:{
            char no_to_find[30];
            printf("请输入要查找的图书编号: ");
            scanf("%s",no_to_find);
            getchar();
            int pos = LocateElem(myList,no_to_find);
            if(pos > 0){
                printf("[成功] 图书'%s'在顺序表的第%d个位置。\n",no_to_find,pos);
            }else{
                printf("[失败] 未找到图书标号为'%s'的书。\n",no_to_find);
            }
            break;
        }
        case 4:{
            int i;
            Book new_book;
            printf("请输入要插入得到位置: ");
            scanf("%d",&i);
            getchar();
            printf("请输入新书的编号: \n");
            scanf("%s",new_book.no);
            getchar();
            printf("请输入新书的书名: \n");
            scanf("%s",new_book.name);
            getchar();
            printf("请输入新书的价格: \n");
            scanf("%f",&new_book.price);
            getchar();

            if (ListInsert(&myList,i,new_book) == OK)
            {
                printf("[成功] 元素已插入到位置 %d。\n",i);
                PrintList(myList);
            }else{
                printf("[失败] 插入失败！位置无效或者顺序表已满。\n");
            }
            break;
        }
        case 5: { // 删除
            int i;
            Book deleted_book;
            printf("请输入要删除元素的位置 : ");
            scanf("%d", &i); getchar();
            if (ListDelete(&myList, i, &deleted_book) == OK) {
                printf("[成功] 已删除位置 %d 的元素，该元素是:\n", i);
                printf("图书编号: %s, 书名: %s, 价格: %.2f\n", deleted_book.no, deleted_book.name, deleted_book.price);
                PrintList(myList);
            } else {
                printf("[失败] 删除失败！位置无效或顺序表为空。\n");
            }
            break;
        }
        case 6: { // 打印
            PrintList(myList);
            break;
        }
        case 0: { // 退出
            printf("程序已退出。感谢使用！\n");
            break;
        }

        default:
            printf("\n[错误] 无效的选项，请输入 0-6 之间的数字。\n\n");
            break;
        }
    }
    

    return 0;
}