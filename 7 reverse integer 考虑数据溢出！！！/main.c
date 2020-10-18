//
//  main.c
//  7. reverse integer
//
//  Created by  周子龙 on 2019/2/19.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int reverse(int x) {
    int Digit[33] = {0};
    int E = 10, i, negetiveflag = 0, Tem;
    if(x < 0)
    {
        x = -x;
        negetiveflag = 1;
    }
    Tem = x;
    for(i = 1; i <= 32 && x != 0 ; i++)
    {
        Tem = x - x/E*10;
        Digit[i] = Tem;
        Digit[0]++;
        x /= E;
    }
    Tem = 0;
    if(Digit[0] > 10 || (Digit[0] == 10 && Digit[1] >= 2))
        return 0;
    for(i = 1; i <= Digit[0]; i++)
    {
        E = pow(10, Digit[0]-i);
        Tem += Digit[i]*E;
    }
    if(negetiveflag)
        Tem = -Tem;
    return Tem;
}

int main(int argc, const char * argv[]) {
    printf("%d\n", reverse(1534236469));
    return 0;
}
