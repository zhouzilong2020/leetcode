//
//  main.c
//  #20 括号问题
//
//  Created by  周子龙 on 2019/1/27.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int bool;

typedef struct stack Stack;
struct stack{
    char kuohao;
    Stack* next; ;
};

Stack* creat_s(){
    Stack* p;
    p = malloc(sizeof(Stack));
    p->next = NULL;
    return p;
}

void push(Stack *top, char s){
    Stack *tem;
    tem = malloc(sizeof(Stack));
    tem->kuohao = s;
    tem->next = top->next;
    top->next = tem;
}

bool comparekuohao(char s, Stack *top){
    char Firstelm;
    Stack *FirstCell;
    FirstCell = top->next;
    Firstelm = FirstCell->kuohao;
    switch (s) {
        case ')':
            if(Firstelm == '(')
                return 1;
            break;
        case ']':
            if(Firstelm == '[')
                return 1;
        case '}':
            if(Firstelm == '{')
                return 1;
    }
    return 0;
}

void pop(Stack * top){
    Stack *FirstCell;
    FirstCell = top->next;
    top->next = FirstCell->next;
    free(FirstCell);
}

bool Isempty(Stack *top){
    if(top->next == NULL)
        return 1;
    else return 0;
}

bool isValid(char* s) {
    Stack *top;
    top = creat_s();
    int len = (int)strlen(s);
    
    int flag = 0;
    
    for(int i = 0; i < len; i++)
    {
        if(s[i] == ' ')
            continue;
        push(top, s[i]);
        flag = comparekuohao(s[i+1], top);
        while(flag)
        {
            pop(top);
            i++;
            if(i < len-1 && !Isempty(top))
                flag = comparekuohao(s[i+1], top);
            else flag = 0;
        }
    }
    
    if(Isempty(top))
        return 1;
    else return 0;
}

int main(int argc, const char * argv[]) {
    char s[] = "()[]{}";
    int a = isValid(s);
    
    printf("%d\n", a);
    return 0;
}
