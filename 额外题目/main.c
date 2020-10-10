//
//  main.c
//  额外题目
//
//  Created by  周子龙 on 2019/2/26.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

void Swap( ElementType *a, ElementType *b ){
    ElementType t = *a; *a = *b; *b = t;
}

void PercDown( ElementType A[], int p, int N )
{ /* 改编代码4.24的PercDown( MaxHeap H, int p )    */
    /* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;
    
    X = A[p]; /* 取出根结点存放的值 */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Child指向左右子结点的较大者 */
        if( X >= A[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}

void HeapSort( ElementType A[], int N )
{ /* 堆排序  直接将A改为最大堆  每次将堆定挪到最后 然后不考虑最后一个 重新调整堆*/
    int i;
    
    for ( i=N/2-1; i>=0; i-- )/* 建立最大堆 */
        PercDown( A, i, N );
    
    for ( i=N-1; i>0; i-- ) {
        /* 删除最大堆顶 */
        Swap( &A[0], &A[i] ); /* 见代码7.1 */
        PercDown( A, 0, i );
    }
}

int singleNumber(int* nums, int numsSize) {
    HeapSort(nums, numsSize);
    int i;
    for(i = 0 ; i < numsSize-1; ){
        if(nums[i] == nums[i+1])
            i += 2;
        else
            return nums[i];
    }
    if(i == numsSize-1)
        return nums[i];
    return -1;
}

int main(int argc, const char * argv[]) {
    const int N = 5;
    int Arr[N] = {1,1,2,3,3};
    int i = singleNumber(Arr, N);
    printf("%d", i);
    return 0;
}
