//
//  main.m
//  Test01
//
//  Created by huixin.a.zhang on 2020/11/2.
//

#import <Foundation/Foundation.h>
void testSum(int n);
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        testSum(10);
    }
    return 0;
}

void testSum(int n){
    int i,sum = 0;
    for (i = 1; i <=n; i++) {
        sum+=i;
    }
    printf("%d\n",sum);
}
