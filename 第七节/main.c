#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Elemtype;
typedef int Status;
typedef struct Node{
    Elemtype data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

Status ListInit(LinkList *L){
    (*L) = (LinkList)malloc(sizeof(Node));
    if ((*L) == NULL) return ERROR;
    (*L)->data = -1;
    (*L)->next = NULL;
    return OK;
}

Status ListInsert(LinkList *L,int index,Elemtype e){
    LinkList p = (*L);
    if (p == NULL) return ERROR;
    int length = 0,i = 0;
    for (p = (*L); p->next != NULL; p = p->next) {
        length++;
    }
    if (index < 1 || index > length + 1) return ERROR;
    for (p = (*L),i = 0;p->next != NULL && i < index -1;p = p->next,i++);
    if (p == NULL) return ERROR;
    LinkList temp = (LinkList)malloc(sizeof(Node));
    if (temp == NULL) return  ERROR;
    temp->data = e;
    temp->next = p->next;
    p->next = temp;
    return OK;
}

Status ListDisplay(LinkList L){
    if (L == NULL) return ERROR;
    LinkList p = L->next;
    while (p){
        printf("%d   ",p->data);
        p = p->next;
    }
    printf("\n");
    return OK;

}

//两个链表求交集
Status ListIntersection(LinkList *La,LinkList *Lb,LinkList *Lc){
    LinkList pa,pb,pc;
    pa = (*La)->next;
    (*Lc) = (*La);
    pc = (*Lc);
    while(pa)
    {	pb = (*Lb)->next;
        while(pb)
        {
            if(pa->data==pb->data)
            {
                LinkList inter = (LinkList)malloc(sizeof(Node));
                if (!inter) return ERROR;
                inter->data = pa->data;
                inter->next = NULL;
                pc->next = inter;
                pc = inter;

            }
            pb=pb->next;
        }
        pa=pa->next;
    }
    return OK;
}
int main() {
    printf("Hello, World!\n");
    LinkList La,Lb,Lc;
    ListInit(&La);
    ListInit(&Lb);
    ListInit(&Lc);
    ListInsert(&La,1,3);
    ListInsert(&La,2,4);
    ListInsert(&La,3,5);
    ListInsert(&La,4,7);

    ListInsert(&Lb,1,1);
    ListInsert(&Lb,2,2);
    ListInsert(&Lb,3,3);
    ListInsert(&Lb,4,4);
    ListInsert(&Lb,5,5);

    ListDisplay(La);
    ListDisplay(Lb);
    ListIntersection(&La,&Lb,&Lc);
    ListDisplay(Lc);
    return 0;
}
