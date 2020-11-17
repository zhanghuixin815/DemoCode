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

//循环链表的创建
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

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        LinkList L;
        CreateList1(&L);
        printf("初始链表为：\n");
        ShowList(L);
    }
    return 0;
}
