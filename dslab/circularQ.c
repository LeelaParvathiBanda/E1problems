#include <stdio.h>
#define MAX 100
int cq[MAX];
int front=-1;
int rear=-1;
void enque(int data){
    if(front==(rear+1)%MAX){
        printf("Queue is full");
    }
    else{
        rear=(rear+1)%MAX;
        cq[rear]=data;
        if(front==-1){
            front=0;
        }
    }
}
void deque(){
    if(front==-1){
        printf("queue is underflow");
    }
    else{
        printf("the deleted element is:%d",cq[front]);
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%100;
        }
    }
}
void display(){
    if(front==-1){
        printf("queue is empty to display");
    }
    else{
        int i=front;
        while(i!=(rear+1)%MAX){
            printf("%d ",cq[i]);
            i=(i+1)%MAX;
        }
    }
}
int main(){
    int n=4;
    while(n!=0){
        printf("\n enter 0->EXIT;1->deque;2->enque;3->DISPLAY: ");
        scanf("%d",&n);
        switch(n){
            case(1):
                deque();
                printf("\nafter dequed:");
                display();
                break;
            case(2):
                int x;
                printf("enter the element to enque: ");
                scanf("%d",&x);
                enque(x);
                printf("after enque: ");
                display();
                break;
            
            case(3):
                printf("the elements in the Queue are/is: ");
                display();
                break;
            
        }
    }

}