//
//  main.c
//  989. 数组形式的整数加法
//
//  Created by  周子龙 on 2019/2/20.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int GetK(int *A, int K){
    int temd = 0, i;
    for(i = 0; i < 5 && K != 0; i++)
    {
        temd = K - K/10*10;
        K /= 10;
        A[4-i] = temd;
    }
    return i;
}

void AddTwoArr(int *A, int *B, int *C, int ASize, int BSize, int CSize){
    int i;
    for(i = 0; i < CSize && i < BSize && i < ASize; i++)
        C[CSize-1-i] = A[ASize-1-i]+B[4-i];
    
    if(i == BSize && BSize != ASize)
        for( ;i < ASize; i++)
            C[CSize-1-i] = A[ASize-1-i];
    
    else if(i == ASize && BSize != ASize)
        for( ;i < BSize; i++)
            C[CSize-1-i] = B[4-i];
    
    for(i = CSize-1; i > 0; i--) //进位
    {
        if(C[i] >= 10)
        {
            C[i] -= 10;
            C[i-1] += 1;
        }
    }
}

int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    int tem[5], BSize = 0, Len, *TEM;
    BSize = GetK(tem, K);
    if(BSize > ASize)
        Len = BSize+1;
    else Len = ASize+1;
    TEM = malloc(sizeof(int) * Len);
    for(int i = 0; i < Len; i++)
        TEM[i] = 0;
    AddTwoArr(A, tem, TEM, ASize, BSize, Len);
    if(TEM[0] == 0)
    {
        returnSize = malloc(sizeof(int) * (Len-1));
        for(int i = 0; i < Len-1; i++)
        {
            returnSize[Len-2-i] = TEM[Len-1-i];
        }
        return returnSize;
    }
    else return TEM;
}

int main(int argc, const char * argv[]) {
    int A[10] = {9,9,9,9,9,9,9,9,9,9};
    int K = 1234;
    int *r;
    r = addToArrayForm(A, 10, K, r);
    for(int i = 0; i < 11; i++)
        printf("%d " , r[i]);
    printf("\n");
    return 0;
}
