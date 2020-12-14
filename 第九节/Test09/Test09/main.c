//
//  main.c
//  Test09
//
//  Created by huixin.a.zhang on 2020/12/14.
//

#include <stdio.h>
//逻辑结构：线性结构，集合结构，树形结构，图形结构
//物理结构：顺序存储结构(连续存储空间)，链式存储结构


//栈结构的顺序存储
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10

typedef int SElemtype;
typedef int Status;
typedef struct {
    SElemtype data[MAXSIZE]; //通过数组开辟一段连续内存
    int top; //栈指针 当栈为空，top = -1;
}SqStack;

//1.创建一个空的栈
Status InitStack(SqStack *S){
    S->top = -1;
    return OK;
}

//2.栈置空
Status ClearStack(SqStack *S){
    S->top = -1;
    printf("栈已清空");
    return OK;
}

//3.判断栈是否为空
int StackEmpty(SqStack S){
    if (S.top == -1) return TRUE;
    return FALSE;
}

//4.获取栈的长度
int StackLength(SqStack S){
    return S.top+1;
}

//5.获取栈定元素的内容
Status GetStackTop(SqStack S,SElemtype *e){
    if (S.top == -1) return ERROR;
    *e = S.data[S.top];
    return OK;
}

//6.入栈
Status PushData(SqStack *S,SElemtype e){
    //判断栈是否满了
    if(S->top == MAXSIZE - 1) return ERROR;
    S->top++;
    S->data[S->top] = e;
    return OK;
}

//7.出栈
Status PopData(SqStack *S,SElemtype *e){
    //判断栈是否满了
    if(S->top == -1) return ERROR;
    *e = S->data[S->top];
    S->top--;
    return OK;
}

//8.栈的遍历
Status StackTraverse(SqStack S){
    if (S.top == -1) {
        printf("此栈为空\n");
        return ERROR;
    }
    int i = 0;
    printf("此栈中的所有元素：\n");
    while (i <= S.top) {
        printf("%d    ",S.data[i]);
        i++;
    }
    printf("\n");
    return OK;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    SqStack S;
    int e,length;
    if (InitStack(&S) == OK) {
        for (int j = 1; j <= 10; j++) {
            PushData(&S, j);
        }
        if (StackEmpty(S) == TRUE) {
            printf("栈为空\n");
        }else{
            printf("栈不为空\n");
        }
        
        StackTraverse(S);
        GetStackTop(S, &e);
        printf("栈顶元素：%d\n",e);
        PopData(&S, &e);
        printf("出栈元素：%d\n",e);
        StackTraverse(S);
        length = StackLength(S);
        printf("栈长度：%d\n",length);
        ClearStack(&S);
        length = StackLength(S);
        printf("栈长度：%d\n",length);
        
    }
    printf("Hello, World!\n");
    return 0;
}
