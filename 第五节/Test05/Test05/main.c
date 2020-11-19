#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1

typedef int Elemtype;
typedef int Status;
typedef struct Node{
    Elemtype data;
    struct Node *prior;
    struct Node *next;
}Node;
typedef struct Node * LinkList;

Status CreateList(LinkList *L){
    LinkList p,temp;
    *L = (LinkList)malloc(sizeof(Node));
    p = *L;
    if (p == NULL) return ERROR;
    p->prior = NULL;
    p->next = NULL;
    p->data = -1;

    for (int i = 0;i < 10;i++){
        //创建临时节点temp
        temp = (LinkList)malloc(sizeof(Node));
        if (temp == NULL) return ERROR;
        temp->prior = NULL;
        temp->next = NULL;
        temp->data = i;
        //把temp放入链表内
        p->next = temp;
        temp->prior = p;
        p = p->next;
    }
    return OK;
}

void DisplayList(LinkList L){
    LinkList  temp;
    temp = L->next;
    if (temp == NULL){
        printf("双向链表为空");
        return;
    }
    while (temp){
        printf("%d   ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    printf("Hello, World!\n");
    LinkList L;
    CreateList(&L);
    DisplayList(L);
    return 0;
}
