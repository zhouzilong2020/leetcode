//
//  main.c
//  #25 K个一组反转列表
//
//  Created by  周子龙 on 2019/1/28.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;
struct ListNode{
    int val;
    struct ListNode *next;
};

ListNode* Creat(){
    ListNode *tem;
    tem = malloc(sizeof(ListNode));
    tem->next = NULL;
    return tem;
}

void pop(ListNode *p){
    if(p->next != NULL)
    {
        ListNode *first;
        first = p->next;
        p->next = first->next;
        free(first);
    }
    else return;
}

void push(ListNode *p, int val){
    ListNode *tem;
    tem = malloc(sizeof(ListNode));
    tem->val = val;
    tem->next = p->next;
    p->next = tem;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    ListNode *stack;
    stack = Creat();
    ListNode *p1, *p2;
    p1 = p2 = head;
    int i;
    int flag = 1;
    while(p1 != NULL)
    {
        i = 0;
        while(i < k && p1 != NULL)
        {
            push(stack, p1->val);
            i++;
            p1 = p1->next;
            if(i < k && p1 == NULL)
                flag = 0;
        }
        
        i = 0;
        while(i < k && flag)
        {
            p2->val = (stack->next)->val;
            i++;
            pop(stack);
            p2 = p2->next;
        }
    }
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
