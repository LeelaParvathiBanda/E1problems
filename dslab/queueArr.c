#include <stdio.h>
#define MAX 100
int arr[MAX];
int start=0;
int rear=-1;
void enque(int x){
    if(rear>MAX-1)
    {
        printf("queue is full.");
    }else{
    rear=rear+1;
    arr[rear]=x;
    }
}
void deque(){
    if(start==-1){
        printf("Queue is empty.");

    }
    else{
    printf("dequed element is: %d",arr[start]);
    start=start+1;
    }
    
}
void display(){
    for(int i=start;i<=rear;i++){
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