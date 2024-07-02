#include <stdio.h>
#define MAX 100 
int arr[MAX];
int top=-1;
void push(int x){
    if(top>=MAX-1){
        printf("stack is full");
    }
    else{
        top=top+1;
        arr[top]=x;

    }

}

void pop(){
    if(top==-1){
        printf("stack is empty");
    }
    else{
        printf("%d",arr[top]);
        top=top-1;
    }
}
void display(){
  
    if(top==-1){
        printf("stack is empty");
    }else{
    for(int i=top;i>=0;i--){
        printf("%d ",arr[i]);
    }
    }
}
int main(){
    int n;
   
    while(n!=0){
        printf("\n enter 0->EXIT;1->POP;2->PUSH;3->DISPLAY : ");
    scanf("%d",&n);
        switch(n){
            case(1):
                pop();
                printf("\nafter popping:");
                display();
                break;
            
            case(2):
                int x;
                printf("enter the element to push: ");
                scanf("%d",&x);
                push(x);
                printf("after pushing: ");
                display();
                break;
            
            case(3):
                display();
                break;
            
           
            
        }
    }
    
   
    }

