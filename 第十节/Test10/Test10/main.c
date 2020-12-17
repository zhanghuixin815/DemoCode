//
//  main.c
//  Test10
//
//  Created by huixin.a.zhang on 2020/12/14.
//

#include <stdio.h>
#include <stdlib.h>
//栈的链式存储
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;

typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack{
    LinkStackPtr top;
    int count;
}LinkStack;

//1.构建空栈
Status InitStack(LinkStack *S){
    S->top = NULL;
    S->count = 0;
    return OK;
}

//2.栈置为空栈
Status ClearStack(LinkStack *S){
    LinkStackPtr p,q;
    p = S->top;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    S->count = 0;
    return OK;
}

//3.判断栈是否为空
Status IsEmpty(LinkStack S){
    return S.count == 0?TRUE:FALSE;
}

//4.获取栈长度
int StackLength(LinkStack S){
    return S.count;
}

//5.获取栈顶元素
Status GetTop(LinkStack S,SElemType *e){
    if (S.top == NULL) return ERROR;
    *e = S.top->data;
    return OK;
}

//6.入栈
Status PushStack(LinkStack *S,SElemType e){
    LinkStackPtr temp = (LinkStackPtr)malloc(sizeof(StackNode));
    if(temp == NULL) return ERROR;
    temp->data = e;
    temp->next = S->top;
    S->top = temp;
    S->count++;
    return OK;
}

//7.出栈
Status PopStack(LinkStack *S,SElemType *e){
    if (IsEmpty(*S) == TRUE) return ERROR;
    LinkStackPtr p;
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;
}

//8.栈的遍历
Status StackTraverse(LinkStack S){
    if (IsEmpty(S) == TRUE) return ERROR;
    LinkStackPtr p;
    p = S.top;
    while (p) {
        printf("%d   ",p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    LinkStack S;
    SElemType e;
    if (InitStack(&S) == OK) {
        for (int i = 1; i <=10; i++) {
            PushStack(&S, i);
        }
        StackTraverse(S);
        int length = StackLength(S);
        printf("栈的长度：%d\n",length);
        GetTop(S, &e);
        printf("栈顶的元素是：%d\n",e);
        PopStack(&S, &e);
        printf("出栈的元素是：%d\n",e);
        length = StackLength(S);
        printf("栈的长度：%d\n",length);
        ClearStack(&S);
        length = StackLength(S);
        printf("栈的长度：%d\n",length);
    }
    return 0;
}
