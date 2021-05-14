//
//  Deque.c
//  Deque
//
//  Created by YOON on 2021/05/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//데이터 형식 지정
typedef int data;

//데이터를 저장할 노드
typedef struct Node{
    struct Node*next;
    struct Node*prev;
    data elem;
}Node;

//Deque 정의.
typedef struct Deque{
    Node*front;
    Node*rear;
}Deque;

//노드 생성 반환.
Node*getNode(data elem){
    Node*tmp=malloc(sizeof(Node));
    tmp->next=NULL;
    tmp->prev=NULL;
    tmp->elem=elem;
    return tmp;
}

//데크 초기화
void initDeque(Deque*dQ){
    dQ->front=NULL;
    dQ->rear=NULL;
    return;
}

//초기상태확인 (초기상태: 1, 초기x:0)
int isEmpty(Deque*dQ){
    if(!dQ->front || !dQ->rear)return 1;
    return 0;
}

//데크 연산 (add_front, add_rear, delete_front, delete_rear, print)

//앞에서 삽입
void add_front(Deque *dQ, data elem){
    //초기상태, 비어있는 경우
    if(isEmpty(dQ)){
        Node*tmp=getNode(elem);
        dQ->front=tmp;
        dQ->rear=tmp;
        return;
    }
    //초기 상태 아닌 경우, 앞에서 삽입.
    Node*tmp=getNode(elem);
    tmp->next=dQ->front;
    dQ->front->prev=tmp;
    dQ->front=tmp;
    return;
}
//뒤에서 삽입
void add_rear(Deque *dQ, data elem){
    //초기상태, 비어있는 경우
    if(isEmpty(dQ)){
        Node*tmp=getNode(elem);
        dQ->front=tmp;
        dQ->rear=tmp;
        return;
    }
    //초기 상태 아닌 경우, 뒤에서 삽입.
    Node*tmp=getNode(elem);
    tmp->prev=dQ->rear;
    dQ->rear->next=tmp;
    dQ->rear=tmp;
    return;
}
//앞에서 제거 (예외발생을 알려주기 위해 반환:1)
int delete_front(Deque*dQ){
    //예외처리.
    if(isEmpty(dQ))return 1;
    //삭제할 노드
    Node*deleteMe=dQ->front;
    //데큐의 front 갱신.
    dQ->front=dQ->front->next;
    //삭제 후, 빈 데큐가 될 수 있으므로 예외처리.
    if(dQ->front) dQ->front->prev=NULL;
    //삭제.
    free(deleteMe);
    return 0;
}
//뒤에서 제거 (예외발생을 알려주기 위해 반환:1)
int delete_rear(Deque*dQ){
    //예외처리.
    if(isEmpty(dQ))return 1;
    //삭제할 노드
    Node*deleteMe=dQ->rear;
    //데큐의 rear 갱신.
    dQ->rear=dQ->rear->prev;
    //삭제 후, 빈 데큐가 될 수 있으므로 예외처리.
    if(dQ->rear) dQ->rear->next=NULL;
    //삭제.
    free(deleteMe);
    return 0;
}

void print(Deque*dQ){
    //예외처리
    if(isEmpty(dQ)){
        printf("\n");
        return;
    }
    //첫 원소부터 출력.
    Node *curr=dQ->front;
    while(curr){
        printf(" %d",curr->elem);
        curr=curr->next;
    }
    printf("\n");
    return;
}
//동적할당해제.
void freeDeque(Deque*dQ){
    //예외처리
    if(isEmpty(dQ))return;
    Node*curr=dQ->front;
    Node*deleteMe=NULL;
    while(curr){
        deleteMe=curr;
        curr=curr->next;
        free(deleteMe);
    }
    return;
}
void startDeque(Deque*dQ){
    //데크 초기화.
    initDeque(dQ);
    //연산의 개수, 명령어(AF,AR,DF,DR,P), 데이터
    int cnt;
    char order[5]={};
    data elem;
    scanf("%d%*c",&cnt);
    for(int i=0;i<cnt;i++){
        scanf("%s%*c",order);
        if(strcmp(order, "AF")==0){
            scanf("%d%*c",&elem);
            add_front(dQ, elem);
        }else if(strcmp(order, "AR")==0){
            scanf("%d%*c",&elem);
            add_rear(dQ, elem);
        }else if(strcmp(order, "DF")==0){
            if(delete_front(dQ)) {
                printf("underflow");
                return;
            }
        }else if(strcmp(order, "DR")==0){
            if(delete_rear(dQ)) {
                printf("underflow");
                return;
            }
        }else if(strcmp(order, "P")==0){
            print(dQ);
        }else{
            continue;
        }
    }
    //남은 할당 해제 unerflow발생시 이미 빈 노드이므로,, 상관없음.
    freeDeque(dQ);
}

int main(){
    Deque dQ;
    startDeque(&dQ);
}


