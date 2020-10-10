//
//  main.c
//  #946 验证栈的序列
//
//  Created by  周子龙 on 2019/1/28.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int bool;
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    if(pushedSize != poppedSize)
        return 0;
    else
    {
        int i = 0, j = 0;
        int Stack[pushedSize+1];
        int StackTop = 0;
        Stack[StackTop++] = pushed[i++];
        while(i < pushedSize)
        {
            while(Stack[StackTop-1] != popped[j] && i < pushedSize)
                Stack[StackTop++] = pushed[i++];
            while(Stack[StackTop-1] == popped[j] && j < pushedSize)
            {
                j++;
                StackTop--;
            }
        }
        if(StackTop == 0)
            return 1;
        else return 0;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int pushedSize = 5;
    int poppedSize = 5;
    int pushed[] = {1,2,3,4,5};
    int popped[] = {4,5,3,2,1};
    int a = validateStackSequences(pushed, pushedSize, popped, poppedSize);
    
    printf("%d\n", a);
    return 0;
}
