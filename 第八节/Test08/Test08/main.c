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
    int temp = 0;
    while (left < right ) {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
    return OK;
}

Status ListLeftRight(int *array,int length,int index){
    if (index > 0 && index < length) {
        Reverse(array, 0, length - 1);
        Reverse(array, 0, length - index - 1);
        Reverse(array, length - index, length - 1);
    }
    return OK;
}

//题目：
// 已知一个整数序列A = {a0,a1,a2,......,an-1},其中0 <= ai <= n,0 <= i <= n,若存在ap1 = ap2 = ...... = apm = x,且m>2/n (0 <= pk < n,1 <= k <= m),则称x为序列A的主元素。例如，A = {0,5,5,3,5,7,5,5} 则5为主元素；若B
// = {0,5,5,3,5,1,5,7},则B没有主元素；现假设有n个元素保存在一个一维数组A中，设计尽可能高效的算法，找出A中主元素，如果存在主元素，返回主元素，不存在返回-1。
//思路：
//1.通过循环计数的方式找到出现次数最多的元素，设置候选主元素。
//2.再次循环，查找候选人具体的出现次数。
//3.将出现次数和数组长素进行比较，如果次数超一半，返回元素，没超过一半则返回-1。

Status MainElemen(int *array,int lenth){
    int count = 1;
    int key = array[0];
    for (int i = 1;i < lenth; i++) {
        if (array[i] == key) {
            count++;
        }else{
            if (count > 0) {
                count--;
            }else{
                key = array[i];
                count = 1;
            }
        }
    }
    
    if (count > 0 ) {
        int i = 0;
        count = 0;
        for (i = 0 , count = 0; i < lenth; i++) {
            if(array[i] == key) count++;
        }
    }
    
    if (count > lenth/2) {
        printf("主元素：%d 出现次数：%d\n",key,count);
        return key;
    }else{
        printf("没找到主元素\n");
        return -1;
    }
    
}

//题目：
/**
 用单链表保存m个整数，结点的结构为(data,link),且data <= n(n为正整数)，请设计一个时间复杂度尽可能高效的算法，去掉链表内绝对值相等的结点，仅保留第一次出现的结点。例如：A = {21,-15,15,7,-15},删除完成后链表变成A = {21,-15,7}。
 
 思路：
 1.时间复杂度高 ==》 用空间换时间
 2.申请n+1个辅助空间数组B，赋初值0
 3.从首元结点遍历，检查B[|data|]
 */

Status DeleteEqualNode(LinkList *L,int n){
    int *p = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        *(p+i) = 0;
    }
    LinkList r = (*L);
    LinkList temp = (*L)->next;
    while (temp != NULL) {
        if (p[abs(temp->data)] == 1) {
            r->next = temp->next;
            free(temp);
            temp = r->next;
        }else{
            p[abs(temp->data)] = 1;
            r = temp;
            temp = temp->next;
        }
    }
    return OK;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    LinkList L;
//    int array[] = {0,0,5,5,1,5,5};
    ListInit(&L);
    ListInsert(&L,1,21);
    ListInsert(&L,2,15);
    ListInsert(&L,3,-15);
    ListInsert(&L,4,7);
    ListInsert(&L,5,15);
    ListDisplay(L);
//    ListInsert(&L,6,11);
//    ListInverse(&L);
//    ListDeleteMinMax(&L, 4, 9);
//    ListDisplay(L);
    
//    ListLeftRight(&array, sizeof(array)/sizeof(array[0]), 3);
//    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
//        printf("%d   ",array[i]);
//    }
//    MainElemen(array, 7);
//    printf("\n");
    DeleteEqualNode(&L, 21);
    ListDisplay(L);
    return 0;
}

