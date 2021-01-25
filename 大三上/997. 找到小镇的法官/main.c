//
//  main.c
//  997. 找到小镇的法官
//
//  Created by  周子龙 on 2019/2/26.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int findJudge(int N, int trust[][2], int trustRowSize, int *trustColSizes) {
    int Indegree[1001] = {0};
    int Outdegree[1001] = {0};
    for(int i = 0; i < trustRowSize; i++)
    {
        Indegree[trust[i][1]]++;
        if(Indegree[trust[i][1]] == N-1)
            return trust[i][1];
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    const int N = 3;
    const int trust[3][2] = {{1,3},{2,3},{3,1}};
    const int trustRowSize = 3;
    const int *trustColSizes;
    printf("%d", findJudge(N, trust, trustRowSize, trustColSizes));
    printf("Hello, World!\n");
    return 0;
}
