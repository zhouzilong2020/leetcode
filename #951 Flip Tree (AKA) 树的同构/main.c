//
//  main.c
//  #951 Flip Tree (AKA) 树的同构
//
//  Created by  周子龙 on 2019/1/29.
//  Copyright © 2019  周子龙. All rights reserved.
//











/*
!!!!!!!!!
注意ascii码的转换！！！！
有时候接受的是char 但是d使用数组的时候需要将char转换为int ，需要减去48
!!!!!!!!!
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree BT;
struct BinaryTree{
    char val;
    struct BinaryTree *Right;
    struct BinaryTree *Left;
};

typedef struct Data Data;
struct Data{
    char val;
    char left;
    char right;
};

/*
BT* SetUp(void){
    int n;
    scanf("%d", &n);
    Data data[n];
    char c, r, l;
    for(int i = 0; i < n; i++)
    {
        scanf("%c %c %c", &c, &r, &l);
        data[i].val = c;
        data[i].right = r;
        data[i].left = l;
        getchar();         //清除回车符；
    }
    
    BT *tem;
    for(int i = 0; i < n; i++)
    {
        tem = malloc(sizeof(BT));
        tem->val = data[i].val;
    }
    
}
*/


void DEBUG_s(Data *data1, Data *data2, int n){
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%c %c\n", data1[i].val, data2[i].val);
    }
}


int main(int argc, const char * argv[]) {
    int n1 = 0;
    scanf("%d", &n1);
    getchar();
    
    Data data1[n1];
    char c, r, l;
    for(int i = 0; i < n1; i++)
    {
        scanf("%c %c %c", &c, &r, &l);
        data1[i].val = c;
        data1[i].right = r;
        data1[i].left = l;
        getchar();         //清除回车符；
    }
    
    int n2 = 0;
    scanf("%d", &n2);
    getchar();
    
    if(n1 != n2)
    {
        printf("No");  //若节点数不同直接判定不同构
        return 0;
    }
    if(n1 == n2 && n1 == 0)
    {
        printf("Yes");
        return 0;
    }
    
    Data data2[n2];
    for(int i = 0; i < n2; i++)
    {
        scanf("%c %c %c", &c, &r, &l);
        data2[i].val = c;
        data2[i].right = r;
        data2[i].left = l;
        if(i != n2-1)
            getchar();         //清除回车符；
    }

    char r1 = 0, l1 = 0, r2 = 0, l2= 0;
    char cl1, cr1, cl2, cr2;
    int i = 0;
    for(int j = 0; i < n1; i++)
    {
        j = 0;
        c = data1[i].val;
        while(data2[j].val != c)
            j++;
        r1 = data1[i].right;
        l1 = data1[i].left;
        r2 = data2[j].right;
        l2 = data2[j].left;
        
      //  DEBUG_s(data1, data2, n1);
        
        if(l1 != '-')
        {
            l1 -= 48;
            cl1 = data1[l1].val;
        }
        else cl1 = 0;
        
        if(r1 != '-')
        {
            r1 -= 48;
            cr1 = data1[r1].val;
        }
        else cr1 = 0;
        
        if(l2 != '-')
        {
            l2 -= 48;
            cl2 = data2[l2].val;
        }
        else cl2 = 0;
        
        if(r2 != '-')
        {
            r2 -= 48;
            cr2 = data2[r2].val;
        }
        else cr2 = 0;
        
        if((cr1 == cr2 && cl1 == cl2) || (cr1 == cl2 && cl1 == cr2))
            continue;
        else
            break;
    }
    
    if(i == n1)
        printf("Yes");
    else printf("No");
}
