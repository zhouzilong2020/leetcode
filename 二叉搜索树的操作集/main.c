//
//  main.c
//  #二叉搜索树的操作集
//
//  Created by  周子龙 on 2019/2/1.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/*
BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );
*/


typedef int ElementType;

typedef struct TreeNode BinTree;
struct TreeNode{
    ElementType val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode *p;
    p = root;
    while(p != NULL)
    {
        if(p->val > val)
            p = p->left;
        else if(p->val < val)
            p = p->right;
        else if(p->val == val)
            return p;
    }
    return p;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if(!root)     //如果树是空的
    {
        root = malloc(sizeof(struct TreeNode));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        if(val > root->val)
            root->right = insertIntoBST(root->right, val);
        else if(val < root->val)
            root->left = insertIntoBST(root->left, val);
    }
    return root;
}


struct TreeNode* findMaxNode(struct TreeNode* root){
    if(!root)        //若树空则返回NULL
        return NULL;
    while(root->right != NULL)
        root = root->right;
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if(root == NULL)     //树为空
        return root;
    if(root->val > key)
        root->left = deleteNode(root->left, key);
    else if(root->val < key)
        root->right = deleteNode(root->right, key);
    else if(root->val == key)           //将删除双儿子节点的情况改为删除一个儿子节或无儿子节点的情况
    {
        struct TreeNode *tem;
        
        if(root->left && root->right) //删除的节点是双儿子节点 则用左子树的最大值取代该位置并删除掉该节点
        {
            tem = findMaxNode(root->left);
            root->val = tem->val;
            root->left = deleteNode(root->left, tem->val);
        }
        else        //删除的节点只有一个子节点或者无子节点
        {
            tem = root;
            if(root->left)
                root = root->left;
            else
                root = root->right;  //这里包含了无子树的情况，因为要么有右子树或者其为空
            free(tem);
        }
    }
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
