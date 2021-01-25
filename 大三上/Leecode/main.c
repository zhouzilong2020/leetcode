//
//  main.c
//  Leecode
//
//  Created by  周子龙 on 2019/1/17.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char s[] = " ";
    int numRows = 0;
    
    unsigned long len = strlen(s);
    int n, m;
//    n = len/(2*numRows-2);
//    m = len%(2*numRows-2);
    
    int space1 = 0, space2 = 0;
    int n;
    void printspace(int n);
    for(int i = 0; i < n; i++){
        if(i == 0 || i == n){
            space1 = numRows + 1;
            for(n = i; i <= len; i+=space1){
                printf("%c", *(s+n));
                printspace(space1);
            }
            printf("\n");
        }
        
        else {
            n = i;
            space1 = numRows - i;
            space2 = numRows - space1;
            while(n < len){
                
            }
        
    }
    
    
    
}

void printspace(int n){
    for(int i = 0; i < n; i++)
        printf(" ");
}
