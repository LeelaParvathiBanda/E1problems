#include <stdlib.h>
#include <stdio.h>
struct node{
    int data;
    struct node *next;
}*start=NULL,*p,*temp;
void push(int x){
    temp=(struct node*)malloc(sizeof(struct node*));
    temp->data=x;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
        p=start;
    }
    else{
        temp->next=start;
        start=temp;
    }
}
void pop(){
    temp=start;
    start=start->next;
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
void peek(){
    printf("%d",start->data);
}

int main(){
   int n;
   
    while(n!=0){
        printf("\nenter 0->EXIT;1->POP;2->PUSH;3->DISPLAY;4->PEEK : ");
    scanf("%d",&n);
        switch(n){
            case(1):

                pop();
                printf("after popping ");
                display();
                break;
            
            case(2):
                int x;
                printf("enter the element to push: ");
                scanf("%d",&x);
                push(x);
                printf("after pushing the elements in the stack: ");
                display();
                break;
            
            case(3):
                display();
                break;
            
            case(4):
                peek();
                break;
            
        }
    }
}