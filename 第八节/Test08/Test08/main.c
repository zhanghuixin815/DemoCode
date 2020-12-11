//
//  main.c
//  Test08
//
//  Created by huixin.a.zhang on 2020/12/10.
//

#include <stdio.h>


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

//将一个链表原地旋转 不能开辟额外空间(头插法 倒序)
Status ListInverse(LinkList *L){
    LinkList p,q;
    //用p记录L的首元结点及以后结点
    p = (*L)->next;
    //L变成新链表的头结点
    (*L)->next = NULL;
    while (p) {
        q = p->next;
        p->next = (*L)->next;
        (*L)->next = p;
        p = q;
    }
    return OK;
}

//设计一个算法，删除递增有序链表内值大于等于min且小于等于max的值，min和max手动指定，可以和链表内元素相同，也可以不同。
Status ListDeleteMinMax(LinkList *L,int min,int max){
    LinkList p,q,pre,temp;
    p = (*L)->next;
    pre = *L;
    //通过遍历找到min之前最后一个结点pre和max之后的第一个结点p
    while (p && p->data < min) {
        pre = p;
        p = p->next;
    }
    while (p && p->data <= max) {
        p = p->next;
    }
    //用q保存第一个待删除的结点
    q = pre->next;
    //把pre和p连起来组成一个新的链表
    pre->next = p;
    //通过遍历删除无用结点
    while (q && q!=p) {
        temp = q;
        q = q->next;
        free(temp);
    }
    return OK;
}

//将n(n>1)个整数存放到一位数组R内，尝试设计一个空间复杂度和时间复杂度尽可能高效的算法，将R中的元素循环左移p个位置(0<p<n)。
//例：
//R = {1,2,3,4,5,6,7} p = 3
//结果 R = {4,5,6,7,1,2,3}
//思路：
//1.将R整体倒置 变成 R={7,6,5,4,3,2,1}
//2.将数组从后往前分割成p个长度 R={7,6,5,4 ||,3,2,1}
//3.将这两部分分别倒置 R = {4,5,6,7,1,2,3} 得到结果

//倒置函数
Status Reverse(int *array,int left,int right){
    int p = left;
    int q = right;
    int temp = 0;
    while (p < q ) {
        temp = array[p];
        array[p] = array[q];
        array[q] = temp;
        p++;
        q--;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    LinkList L;
    ListInit(&L);
    
    ListInsert(&L,1,3);
    ListInsert(&L,2,5);
    ListInsert(&L,3,7);
    ListInsert(&L,4,8);
    ListInsert(&L,5,10);
    ListInsert(&L,6,11);

    ListDisplay(L);
//    ListInverse(&L);
    ListDeleteMinMax(&L, 4, 9);
    ListDisplay(L);
    return 0;
}

