//
//  main.c
//  98. Validate Binary Search Tree
//
//  Created by  周子龙 on 2019/2/19.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode Tree;
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void InorderTraversal(Tree *root, int *A){
    if(root){
        InorderTraversal( root->left, A);
        A[++A[0]] = root->val;
        InorderTraversal( root->right, A);
    }
}

bool Judge(int *A){
    int i;
    for(i = 2; i <= A[0]; i++)
    {
        if(A[i] <= A[i-1])
            break;
    }
    if(i == A[0]+1)
        return true;
    else return false;
}

bool isValidBST(struct TreeNode* root) {
    int asistance[9999] = {0};
    InorderTraversal(root, asistance);
    if(Judge(asistance))
        return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
