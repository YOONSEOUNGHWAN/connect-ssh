//
//  main.c
//  postfix_operator
//
//  Created by YOON on 2021/05/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//데이터 형식 지정.
typedef char data;

//스택 구현.
typedef struct Stack{
    data *arr;
    int top;
    int size;
}Stack;

//스택 만들기 & 초기화
void mkStack(Stack*st,int size){
    st->arr=malloc(sizeof(data)*size);
    memset(st->arr, -1, size);
    st->top=-1;
    st->size=size;
    return;
}
//스택 초기화.
void init_Stack(Stack*st){
    memset(st->arr, -1, st->size);
    st->top=-1;
}

//스택 함수 구현.
//가득 찼는지..
int isFull(Stack*st){
    if(st->top +1 ==st->size){
        printf("Stack FULL\n");
        return 1;
    }
    return 0;
}

//비어있는지..
int isEmpty(Stack*st){
    if(st->top==-1){
        printf("Stack Empty\n");
        return 1;
    }
    return 0;
}

void Push(Stack*st, data elem){
    if(isFull(st)) return;
    st->arr[++st->top]=elem;
    return;
}

data POP(Stack*st){
    if(isEmpty(st)) return 0;
    return st->arr[st->top--];
}

void Peek(Stack*st){
    if(isEmpty(st)) return;
    printf("%c",st->arr[st->top]);
    return;
}

void duplicate(Stack*st){
    if(isFull(st))return;
    data duple=POP(st);
    Push(st, duple);
    Push(st, duple);
    return;
}

void upRotate(Stack*st,int n){
    if(st->top+1 < n) return;
    data *tmp=malloc(sizeof(data)*n);
    for(int i=0;i<n;i++){
        tmp[i]=POP(st);
    }
    char temp;
    //rotate
    temp=tmp[0];
    for(int i=0;i<n-1;i++){
        tmp[i]=tmp[i+1];
    }
    tmp[n-1]=temp;
    for(int i=n-1;i>=0;i--){
        Push(st, tmp[i]);
    }
    free(tmp);
}

void downRotate(Stack*st, int n){
    if(st->top+1 < n) return;
    data *tmp=malloc(sizeof(data)*n);
    for(int i=0;i<n;i++){
        tmp[i]=POP(st);
    }
    char temp;
    //rotate
    temp=tmp[n-1];
    for(int i=n-2;i>=0;i--){
        tmp[i+1]=tmp[i];
    }
    tmp[0]=temp;
    for(int i=n-1;i>=0;i--){
        Push(st, tmp[i]);
    }
    free(tmp);
}

void print(Stack*st){
    for(int i=st->top; i>=0;i--){
        printf("%c",st->arr[i]);
    }
    printf("\n");
    return;
}
void freeStack(Stack*st){
    free(st->arr);
    return;
}









