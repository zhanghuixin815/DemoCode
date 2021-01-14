//
//  main.m
//  001--队列的顺序存储
//
//  Created by 张慧鑫 on 2021/1/13.
//

#include <stdio.h>
//队列
/*
 结合工程内的截图看
 判断队列为空:
 Q.front == Q.rear
 判断队列是否已满：
 (Q.rear + 1) % MAXSIZE == Q.front
 */

//队列的顺序存储
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int QElemtype;

typedef struct QNode{
    int data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

//初始化
Status QueueInit(SqQueue *Q){
    Q->front = 0;
    Q->rear = 0;
    return OK;
}
//清空
Status QueueClear(SqQueue *Q){
    Q->front = 0;
    Q->rear = 0;
    return OK;
}
//是否为空
int QueueIsEmpty(SqQueue Q){
    if (Q.front == Q.rear) return TRUE;
    return FALSE;
}
//长度
int QueueLength(SqQueue Q){
    return (Q.rear -Q.front + MAXSIZE) % MAXSIZE;
}
//获取队头
int QueueHead(SqQueue Q){
    if (QueueIsEmpty(Q) == TRUE) return ERROR;
    return Q.data[Q.front];
}
//入队
Status QueueIn(SqQueue *Q,QElemtype e){
    if ((Q->rear + 1) % MAXSIZE == Q->front) return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return OK;
}
//出队
Status QueueOut(SqQueue *Q,QElemtype *e){
    if (QueueIsEmpty(*Q) == TRUE) return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return OK;
}
//遍历
void QueueDisplay(SqQueue Q){
    int i = Q.front;
    while (i != Q.rear) {
        printf("%d   ",Q.data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    SqQueue Q;
    QElemtype e;
    QueueInit(&Q);
    QueueIn(&Q, 10);
    QueueIn(&Q, 20);
    QueueOut(&Q, &e);
    printf("%d\n",e);
    QueueIn(&Q, 30);
    QueueIn(&Q, 40);
    QueueIn(&Q, 50);
    QueueIn(&Q, 60);
    QueueOut(&Q, &e);
    printf("%d\n",e);
    QueueDisplay(Q);
    printf("%d\n",QueueHead(Q));
    printf("%d\n",QueueLength(Q));
    printf("%d\n",QueueIsEmpty(Q));
    printf("%d\n",QueueClear(&Q));
    printf("%d\n",QueueIsEmpty(Q));
    return 0;
}

