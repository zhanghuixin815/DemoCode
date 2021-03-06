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
    if (*L == NULL) return ERROR;
    (*L)->prior = NULL;
    (*L)->next = NULL;
    (*L)->data = -1;
    p = (*L);
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
        printf("双向链表为空\n");
        return;
    }
    while (temp){
        printf("%d   ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//双向链表插入
Status InsertList(LinkList *L,int place,Elemtype e){
    //判断位置是否合法
    if(place < 1) return ERROR;
    //新建结点
    LinkList temp = (LinkList)malloc(sizeof(Node));
    temp->data = e;
    temp->prior = NULL;
    temp->next = NULL;
    LinkList p = (*L);
    //找到插入位置的前一个位置的结点
    for(int i = 1;i < place && p != NULL;i++,p = p->next);
    if (p == NULL) return ERROR;
    if (p->next == NULL) {
        //将结点插入链表(末尾)
        p->next = temp;
        temp->prior = p;
    }else{
        //将结点插入链表(非末尾)
        p->next->prior = temp;
        temp->next = p->next;
        p->next = temp;
        temp->prior = p;
    }
    
    return OK;
    
}

//双向链表删除(通过位置查找 删除)
Status DeleteListByIndex(LinkList *L,int place,Elemtype *e){
    if(place < 1) return ERROR;
    LinkList p = *L;
    //判断链表是否为空，空的话不作操作
    if (*L == NULL) return ERROR;
    //找到待删除位置的前一个结点
    for(int i = 1;i < place && p != NULL;i++,p = p->next);
    if(!p || !p ->next) return ERROR;
    LinkList delTemp = p->next;
    *e = delTemp->data;
    p->next = delTemp->next;
    if (delTemp->next != NULL) delTemp->next->prior = p;
    free(delTemp);
    return OK;
}

//双向链表删除(通过内容查找 删除,只删除发现的首个结点)
Status DeleteListByContent(LinkList *L,Elemtype data){
    LinkList p = *L;
    while (p) {
        if (p->data == data) {
            //找到位置之后开始删除
            p->prior->next = p->next;
            if (p->next != NULL) p->next->prior = p->prior;
            free(p);
            break;
        }
        p = p->next;
    }
    return OK;
}

//双向链表查找 替换
Status ReplaceList(LinkList *L,Elemtype data,Elemtype e,Elemtype *place){
    LinkList p = (*L)->next;
    int i = 1;
    while (p) {
        if (p->data == data) {
            //找到位置之后开始删除
            p->data = e;
            *place = i;
            break;
        }
        i++;
        p = p->next;
    }
    return OK;
}


int main() {
    printf("Hello, World!\n");
    LinkList L;
    Elemtype e;
    Elemtype place;
    CreateList(&L);
    DisplayList(L);
    InsertList(&L, 11, 1);
    DisplayList(L);
    DeleteListByContent(&L, 99);
    DisplayList(L);
//    DeleteListByIndex(&L, 10, &e);
//    DisplayList(L);
//    printf("%d\n",e);
//    ReplaceList(&L,1,2,&place);
//    DisplayList(L);
//    printf("%d\n",place);
    return 0;
}
