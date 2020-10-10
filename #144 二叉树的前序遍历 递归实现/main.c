//
//  main.c
//  二叉树的前序遍历
//
//  Created by  周子龙 on 2019/1/29.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;
void preTraversal(TreeNode *root, int *returnarr, int *returnSize){
    if(root)
    {
        returnarr[(*returnSize)++] = root->val;  //只要读取数据就加一
        preTraversal(root->left, returnarr, returnSize);
        preTraversal(root->right, returnarr, returnSize);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *returnarr = malloc(1000*sizeof(int));
    *returnSize = 0;  //利用其来记录数组的位置
    preTraversal(root, returnarr, returnSize);
    return returnarr;
}

//问题是这个的接口Size若比较大怎么办， returnSize究竟存了什么




int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
