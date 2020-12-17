//
//  main.c
//  Test11
//
//  Created by huixin.a.zhang on 2020/12/16.
//

#include <stdio.h>
//栈与递归
/*
 何时使用：
 1.数学定义本身就是递归(阶乘，斐波拉契数列)
 2.数据结构是递归的 (链表的结构是递归 结点的next指向下一个结点，二叉树结构也是)
 3.问题是递归的
*/
/*
 分治法(递归)：
 1.大问题可以拆解成小问题，并且大问题与小问题的解决发办法高度雷同
 2.拆解后问题变得简单，可以解决
 3.必须要有一个递归出口，要有递归边界
 */

//斐波那契数列实现
int Fbi(int i){
    if (i < 2) {
        return i == 0?0:1;
    }
    return Fbi(i - 1)+Fbi(i - 2);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    for (int i = 0; i < 10; i++) {
        printf("%d   ",Fbi(i));
    }
    return 0;
}
