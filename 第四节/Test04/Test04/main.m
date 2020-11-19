//
//  main.m
//  Test04
//
//  Created by huixin.a.zhang on 2020/11/12.
//

#import <Foundation/Foundation.h>

#define OK 1
#define ERROR 0

typedef int Elemtype;
typedef int Status;

typedef struct Node{
    Elemtype data;
    struct Node *next;
}Node;

typedef struct Node *LinkList;

//单向循环链表的创建
/*
 2种情况：
 1⃣️ 第一次创建
 2⃣️ 已经创建，新增数据
 1.判断是不是第一次新建
 YES 创建新节点 新结点next ->本身
 NO 链表结尾的位置 尾结点next->新结点 新节点next-> 首元结点
 */

//循环法找循环链表尾结点
Status CreateList(LinkList *L){
    int item;
    LinkList temp,target = NULL;
    printf("请输入结点的值，输入0结束\n");
    while (1) {
        scanf("%d",&item);
        if (item == 0) break;
        if (*L == NULL) {
            *L = (LinkList)malloc(sizeof(Node));
            if (*L == NULL) return ERROR;
            (*L)->data = item;
            (*L)->next = *L;
        }else{
            //通过找到循环链表最后一个节点
            for (target = *L; target->next != *L; target = target->next);
            
            temp = (LinkList)malloc(sizeof(Node));
            if (temp == NULL) return  ERROR;
            temp->data = item;
            temp->next = *L;
            target->next = temp;
        }
    }
    return OK;
}

void ShowList(LinkList L){
    LinkList p;
    p = L;
    do {
        printf("%5d",p->data);
        p = p->next;
    } while (p != L);
    printf("\n");
    
}

//指针法找循环链表尾结点
Status CreateList1(LinkList *L){
    int item;
    LinkList temp,r = NULL;
    printf("请输入结点的值，输入0结束\n");
    while (1) {
        scanf("%d",&item);
        if (item == 0) break;
        if (*L == NULL) {
            *L = (LinkList)malloc(sizeof(Node));
            if (*L == NULL) return ERROR;
            (*L)->data = item;
            (*L)->next = *L;
            r = *L;
        }else{
            //通过指针找到循环链表最后一个节点
            temp = (LinkList)malloc(sizeof(Node));
            if (temp == NULL) return  ERROR;
            temp->data = item;
            temp->next = *L;
            r ->next = temp;
            r = temp;
        }
    }
    return OK;
}

//单向循环链表插入数据
//1.插入的位置在首结点
//判断插入的位置是否在首元结点上
//创建新结点，并赋值给新结点
Status InsertList(LinkList *L,int place,int num){
    LinkList temp,target = NULL;
    int i;
    if (place == 1) {
        //1.创建temp，判断成功与否
        //2.通过循环找到链表最后一个结点
        //3.新结点->next指向头结点*L
        //4.尾结点->next指向新结点
        //5.让*L指向新结点
        temp = (LinkList)malloc(sizeof(Node));
        if(temp == NULL) return ERROR;
        temp->data = num;
        temp->next = *L;
        for (target = *L; target->next != *L; target = target->next);
        target->next = temp;
        *L = temp;
    }else{
        //1.创建temp，判断成功与否
        //2.通过循环找到链表待插入位置的前一个结点target
        //3.新结点->next指向target->next
        //4.target->next指向temp
        temp = (LinkList)malloc(sizeof(Node));
        if(temp == NULL) return ERROR;
        for (i = 1,target = *L; target->next != *L && i < place-1; target = target->next,i++);
        temp->next = target->next;
        temp->data = num;
        target->next = temp;
    }
    return  OK;
}

//循环链表删除元素
Status DeleteList(LinkList *L,int place){
    LinkList temp,target;
    int i;
    temp = *L;
    if (temp == NULL || place < 1) return  ERROR;
    if (place == 1) {
        //1.如果删除的是首元结点
        //找到尾结点
        //新结点作为头结点
        for(target = *L;target->next != *L;target = target->next);
        temp = *L;
        *L = (*L)->next;
        target->next = *L;
        free(temp);
    }else{
        //2.删除其他位置的结点
        //找到删除的位置的前一个结点 target
        ///用一个临时变量指向待删除的结点temp
        // target->next指向temp->next
        //free temp
        for (i = 1,target = *L; target->next != *L && i < place-1; target = target->next,i++);
        temp = target->next;
        target->next = temp->next;
        free(temp);
    }
    return  OK;
}

//单向循环链表查询
int FindValue(LinkList L,int value){
    int i = 1;
    LinkList p;
    p = L;
    while (p->data != value && p->next != L) {
        i++;
        p = p->next;
        
    }
    if (p->data == value) {
        return i;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        LinkList L;
        int place,num;
        CreateList1(&L);
        printf("初始链表为：\n");
        ShowList(L);
//        printf("输入要插入的位置和数据:");
//        scanf("%d %d",&place,&num);
//        InsertList(&L, place, num);
//        ShowList(L);
//        printf("输入要删除的位置:");
//        scanf("%d",&place);
//        DeleteList(&L, place);
//        ShowList(L);
        printf("输入要查找的值:");
        scanf("%d",&num);
        place = FindValue(L, num);
        if (place != -1) {
            printf("找到的值的位置是:%d\n",place);
        }else{
            printf("未找到值\n");
        }
        
    }
    return 0;
}
