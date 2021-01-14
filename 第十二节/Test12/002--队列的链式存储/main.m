//
//  main.m
//  002--队列的链式存储
//
//  Created by 张慧鑫 on 2021/1/13.
//

#import <Foundation/Foundation.h>
//队列的链式存储
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int QElemtype;

typedef struct QNode{
    QElemtype data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
    int length;
}LinkQueue;

//队列初始化
Status QueueInit(LinkQueue *Q){
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front && !Q->rear) return ERROR;
    Q->front->next = NULL;
    Q->length = 0;
    return OK;
}

//队列销毁 销毁所有节点(Q->front也释放掉)
Status QueueDestory(LinkQueue *Q){
    while (Q->front) {
        Q->rear = Q->front;
        free(Q->front);
        Q->front = Q->rear;
    }
    Q->length = 0;
    return OK;
}

//队列清空 保留头结点(Q->front保留)
Status QueueClear(LinkQueue *Q){
    QueuePtr p,q;
    Q->rear = Q->front;
    p = Q->front->next;
    Q->front->next = NULL;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    Q->length = 0;
    return OK;
}

//队列是否为空
Status QueueIsEmpty(LinkQueue Q){
    if (Q.front == Q.rear) return TRUE;
    return FALSE;
}

//获取队列长度
int GetLength(LinkQueue Q){
    return Q.length;
}

//获取队头
int GetHead(LinkQueue Q){
    if(QueueIsEmpty(Q) == TRUE) return ERROR;
    return Q.front->next->data;
}

//入队
Status QueueIn(LinkQueue *Q,QElemtype e){
    QueuePtr temp = (QueuePtr)malloc(sizeof(QNode));
    if(!temp) return ERROR;
    temp->next = NULL;
    temp->data = e;
    Q->rear->next = temp;
    Q->rear = temp;
    Q->length++;
    return OK;
}

//出队
Status QueueOut(LinkQueue *Q,QElemtype *e){
    QueuePtr node = Q->front->next;
    *e = node->data;
    Q->front->next = node->next;
    //当删除的是队尾元素时，将队尾指针指向头结点
    if (node == Q->rear)
    {
        Q->rear = Q->front;
    }
    Q->length--;
    return OK;
}

//遍历
void QueueDisplay(LinkQueue Q)
{
    QueuePtr p = Q.front->next;
    while (p)
    {
        printf("%d   ", p->data);
        p = p->next;
    }
    printf("\n");
}




int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        LinkQueue Q;
        QElemtype e;
        QueueInit(&Q);
        QueueIn(&Q, 10);
        QueueIn(&Q, 20);
        QueueIn(&Q, 30);
        QueueIn(&Q, 40);
        QueueOut(&Q, &e);
        printf("%d\n",e);
        printf("%d\n",GetLength(Q));
        printf("%d\n",GetHead(Q));
        QueueDisplay(Q);
        
        
    }
    return 0;
}
