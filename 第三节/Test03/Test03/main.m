//
//  main.m
//  Test03
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

//创建链表并加入头结点 头结点数据域为空，指针指向空
Status ListInit(LinkList *L){
    *L = (LinkList)malloc(sizeof(Node));
    if (L == NULL) {
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}

Status ListTraverse(LinkList L){
    //指针p指向头结点的下一个结点(首元结点)
    LinkList p = L->next;
    while (p) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

Status ListInsert(LinkList *L,int i,Elemtype e){
    int j = 1;
    LinkList p,s;
    p = *L;
    
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListIndex(LinkList L,int i){
    int j = 1;
    LinkList p,s;
    p = L;
    
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return ERROR;
    }
    s = p->next;
    printf("%d\n",s->data);
    return OK;
}

Status ListDelete(LinkList *L,int i){
    int j = 1;
    LinkList p,s;
    p = *L;
    
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return ERROR;
    }
    s = p->next;
    p->next = s->next;
    printf("删除的元素为 %d\n",s->data);
    free(s);
    return OK;
}

//创建单链表 头插法
void CreateListHead(LinkList *L,int n){
    LinkList p;
    //创建一个带头结点的单链表
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for (int i = 1; i <= n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->next = (*L)->next;
        p->data = i;
        (*L)->next = p;
    }
}

//创建单链表 尾插法
void CreateListTail(LinkList *L,int n){
    LinkList p,r;
    *L = (LinkList)malloc(sizeof(Node));
    r = *L;
    for (int i = 1; i <= n; i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = i;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        LinkList L;
        Status iStatus = ListInit(&L);
        printf("%d\n",iStatus);
        
//        for (int i = 1; i <= 10; i++) {
//            ListInsert(&L, 1, i);
//        }
        
//        CreateListHead(&L,20);
        CreateListTail(&L,20);
        ListTraverse(L);
        ListIndex(L, 3);
        ListDelete(&L, 3);
        ListTraverse(L);
        
        
    }
    return 0;
}
