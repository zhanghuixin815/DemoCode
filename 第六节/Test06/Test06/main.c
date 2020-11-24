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

//双向循环链表的创建
Status CreateList(LinkList *L){
    (*L) = (LinkList)malloc(sizeof(Node));
    if (*L == NULL) return ERROR;
    (*L)->next = (*L);
    (*L)->prior = (*L);
    (*L)->data = -1;
    return OK;
}

//双向链表插入元素
Status InsertList(LinkList *L,int index,Elemtype e){
    if ((*L) == NULL) return ERROR;
    int length = 0;
    LinkList p = (*L);
    while (p->next != (*L)){
        p = p->next;
        length++;
    }
    p = (*L);
    if (index < 1 || index > length + 1) return ERROR;
    for (int i = 1; i < index && p->next != (*L); i++,p = p->next);
    LinkList temp = (LinkList)malloc(sizeof(Node));
    if (temp == NULL) return ERROR;
    temp->data = e;
    temp->prior = p;
    temp->next = p->next;
    p->next->prior = temp;
    p->next = temp;

    return OK;
}

//双向循环链表的遍历
Status DisplayList(LinkList L){
    if (L == NULL){
        printf("双向循环链表为空，返回");
        return ERROR;
    }
    LinkList p = L;
    do{
        p = p->next;
        printf("%d   ",p->data);

    }while (p->next != L);
    printf("\n");
    return OK;

}

//双向循环链表删除元素
Status DeleteList(LinkList *L,int index,Elemtype *e){
    if ((*L) ==NULL) return ERROR;
    int i = 1;
    int length = 0;
    LinkList p = (*L);
    while (p->next != (*L)){
        p = p->next;
        length++;
    }
    if (index < 1 || index >= length + 1) return ERROR;
    LinkList temp = (*L)->next;
    if (temp->next == (*L)){
        free(*L);
        (*L) = NULL;
        return OK;
    }
    while (i < index){
        temp = temp->next;
        i++;
    }
    *e = temp->data;
    temp->prior->next = temp->next;
    temp->next->prior = temp->prior;
    free(temp);
    return OK;
}

int main() {
    LinkList L;
    Elemtype e;
    Status istatus = CreateList(&L);
    printf("%d\n", istatus);
    for (int i = 1; i <= 10; ++i) {
        InsertList(&L, i, i);
    }
    DisplayList(L);
    InsertList(&L, 2, 99);
    DisplayList(L);
    DeleteList(&L,11,&e);
    DisplayList(L);
    printf("%d",e);
}