//
//  main.c
//  #100 树的同构
//
//  Created by  周子龙 on 2019/1/29.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
typedef int bool;

/*
int Firsttravasal(struct TreeNode* p, struct TreeNode* q){
    int tem1 = 0, tem2 = 0;
    int flag1 = 1, flag2 = 1;
    if(p || q)
    {
        tem1 = p->val;   //完全可已将这个赋值语句和下面的判断结合一下，省了时间
        tem2 = q->val;
        flag1 = Firsttravasal(p->left, q->left);
        flag2 = Firsttravasal(p->right, q->right);
    }
    
    if(tem1 == tem2 && flag1 && flag2)
        return 1;
    else return 0;
}

typedef struct TreeNode TreeNode;
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    return Firsttravasal(p,q);
}
*/


/***
 *
 *VERSON 2.0
 *
 ***/

int Firsttravasal(struct TreeNode* p, struct TreeNode* q){
    int tem1 = 0, tem2 = 0;
    int flag1 = 1, flag2 = 1;
    if(p && q)
    {
        if(p->val != q->val)
            return 0;
        flag1 = Firsttravasal(p->left, q->left);
        flag2 = Firsttravasal(p->right, q->right);
    }
    if((!p && q) || (p && !q))
        return 0;
    if(flag1 && flag2)
        return 1;
    return 0;
}

typedef struct TreeNode TreeNode;
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    return Firsttravasal(p,q);
}



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
