#include <stdio.h>
#define MAX 100

int arr[MAX];
int front =-1;
int rear=-1;
void deque(){
    if(front==-1){
        printf("queue is empty");
    }
    else{
        printf("the deleted element is:%d",arr[front++]);
        
    }
}
void enque(int val){
    if(rear>=MAX){
         printf("queue is full");
    }
    else{
       int pos=rear;
        rear=rear+1;
        while(pos>=0&&arr[pos]>=val){
            arr[pos+1]=arr[pos];
            pos=pos-1;
        }
        arr[pos+1]=val;
        if(front==-1){
            front=0;
        }
    }
}
void display(){
    for(int i=front;i<=rear;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
   
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
                printf("the elements in the Queue is/are:");
                display();
                break;
            
        }
    }


    
}