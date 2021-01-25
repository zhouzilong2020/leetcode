//
//  main.c
//  #155 最小栈
//
//  Created by  周子龙 on 2019/1/27.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct MinStack MinStack;
struct MinStack{
    int val;
    int min;
    struct MinStack *next;
};

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *top;
    top = malloc(sizeof(MinStack));
    top->next = NULL;
    return top;
}

void minStackPush(MinStack* obj, int x) {
    MinStack *tem;
    tem = malloc(sizeof(MinStack));
    if(obj->next == NULL)
    {
        tem->val = x;
        tem->next = obj->next;
        tem->min = x;
    }
    else
    {
        tem->val = x;
        tem->next = obj->next;
        if(x < (obj->next)->min)
            tem->min = x;
        else
            tem->min = (obj->next)->min;
    }
    obj->next = tem;
}

void minStackPop(MinStack* obj) {
    if(obj->next == NULL)
        return;
    else
    {
        MinStack *FirstCell;
        FirstCell = obj->next;
        obj->next = FirstCell->next;
        free(FirstCell);
    }
}

int minStackTop(MinStack* obj) {
    int topval;
    MinStack *FirstCell;
    FirstCell = obj->next;
    topval = FirstCell->val;
    return topval;
}

int minStackGetMin(MinStack* obj) {
    int min;
    min = (obj->next)->min;
    return min;
}

void minStackFree(MinStack* obj) {
    while(obj->next != NULL)
        minStackPop(obj);
    free(obj);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
