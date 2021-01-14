//
//  main.m
//  Test02
//
//  Created by huixin.a.zhang on 2020/11/12.
//

#import <Foundation/Foundation.h>
//线性表->顺序存储 (逻辑相邻，物理存储也相邻)
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct {
    ElemType *data;
    int length;
}sqlist;

//1.初始化空表
Status ListInit(sqlist *L){
    L->data = calloc(MAXSIZE, sizeof(ElemType));
    if (!L->data) {
        return ERROR;
    }
    L->length = 0;
    return OK;
}

Status ListOutput(sqlist L){
    int i;
    for (i = 0; i < L.length; i++) {
        printf("%d\n",L.data[i]);
    }
    printf("\n");
    return OK;
}

//顺序表插入
//1.是否存在，位置是否合法
//2.找到插入位置进行位移 length+1

Status ListInsert(sqlist *L,int i,ElemType e){
    //判断插入位置是否合法
    if ((i < 1) || (i > L->length + 1)) {
        return  ERROR;
    }
    //判断存储空间是否已满
    if (L -> length == MAXSIZE) {
        return ERROR;
    }
    if (i<=L->length) {
        for (int j = L->length - 1; j > i - 1; j--) {
            L->data[j+1] = L->data[j];
        }
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}

//顺序表删除
//1.是否存在，位置是否合法
//2.删除链表的第i个元素，length-1

Status ListDelete(sqlist *L,int i){
    //判断长度是否为空
    if (L->length == 0) {
        return ERROR;
    }
    //判断删除位置是否合法
    if ((i < 1) || (i > L->length + 1)) {
        return  ERROR;
    }
    for (int j = i; j < L->length; j++) {
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return OK;
}

//清空顺序表
//直接将长度给0
Status ClearList(sqlist *L){
    L->length = 0;
    return OK;
}



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        sqlist L;
        Status iStatus;
        iStatus = ListInit(&L);
        printf("%d\n",iStatus);
        
        
    }
    return 0;
}
