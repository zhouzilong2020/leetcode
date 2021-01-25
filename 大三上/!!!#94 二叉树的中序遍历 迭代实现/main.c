//
//  main.c
//  #94 二叉树的中序遍历 迭代实现
//
//  Created by  周子龙 on 2019/1/29.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define NOVALUE -9999;

typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct Stack Stack;
struct Stack{
    int val;
    TreeNode *add;
    struct Stack *next;
};

Stack* CreatStack(){
    Stack *p;
    p =  malloc(sizeof(Stack));
    p->next = NULL;
    p->add = NULL;
    return p;
}

void Push(Stack *p, TreeNode* T){
    Stack *First;
    int val = T->val;
    First = malloc(sizeof(Stack));
    First->add = T;
    First->val = val;
    First->next = p->next;
    p->next = First->next;
}

int Pop(Stack *p){
    Stack *First;
    First = p->next;
    if(First)
    {
        int val;
        val = First->val;
        p->next = First->next;
        free(First);
        return val;
    }
    return NOVALUE;
}

TreeNode *Popadd(Stack *S){
    Stack *first;
    first = S->next;
    if(first == NULL)
        return NULL;
    return first->add;
}

typedef int bool;
bool Isempty(Stack *p){
    if(p->next)
        return 1;
    else return 0;
}

void inorder(int* returnSize, TreeNode* root, int* returnarr){
    Stack *S;
    S = CreatStack();
    TreeNode *T;
    T = root;
    
    while(!Isempty(S) || T) //栈不是空的或者节点不是子节点
    {
        while(T)
        {
            Push(S, T);
            T = T->left;
        }
        T = Popadd(S);
        returnarr[(* returnSize)++] = Pop(S);
        if(T != NULL)
            T = T->right;
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *returnarr;
    returnarr = malloc(sizeof(int) * 1000);
    *returnSize = 0;
    inorder(returnSize, root, returnarr);
    return returnarr;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
