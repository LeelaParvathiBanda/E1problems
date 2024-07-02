#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node* prev;
    int data;
    struct node* next;
}*start=NULL,*p,*temp,*rear;
void enque(int x){
    temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=temp->next=NULL;
    temp->data=x;
    if(start==NULL){
        start=temp;
        rear=temp;
        
    }
    else{
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
}
void deque(){
    temp=start;
    start=start->next;
    start->prev=NULL;
    temp->next=NULL;
    free(temp);
}
void display(){
    p=start;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
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
                printf("the elements in the Queue are/is: ");
                display();
                break;
            
        }
    }


}