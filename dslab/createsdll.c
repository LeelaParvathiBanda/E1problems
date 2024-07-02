#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
}*start=NULL,*p,*temp;
int main(){
    int n;
    printf("enter the no.of elements for DLL: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        temp=(struct node *)malloc(sizeof(struct node));
        int x;
        printf("enter the %d element: ",i+1);
        scanf("%d",&x);
        temp->data=x;
        temp->prev =temp->next=NULL;
        if(start==NULL){
            start=temp;
            p=temp;
        }
        else{
            p->next=temp;
            temp->prev=p;
            p=temp;
           
        }
    } 
    if(start==NULL){
        printf("double linked list is empty");
    }
    else{
    printf("the elements of the doubly linked list: ");
    p=start;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    }
    printf("\n");
    int ele,pos=0,flag=0;
    printf("enter the element to be deleted: ");
    scanf("%d",&ele);
    p=start;
    while(p!=NULL){
        pos++;
        if(p->data==ele){
            flag=1;
            break;
        }
        p=p->next;
    }
   
    if(flag==0){
        printf("element not found");
    }
    else{
        p=start;
        if(pos==1){
            temp=start;
            start=start->next;
            temp->next=NULL;
            start->prev=NULL;
            free(temp);
        }
        else if(pos==n){
            while(p->next->next!=NULL){
                p=p->next;
            }
            temp=p->next;
            temp->prev=NULL;
            p->next=NULL;
            free(temp);
        }
        else{
            for(int i=1;i<pos-1;i++)
                p=p->next;
            temp=p->next;
            p->next=temp->next;
            temp->next->prev=p;
            temp->next=temp->prev=NULL;
            free(temp);
        }
        
    }
    printf("the elements after deletion of the double LL: ");
        p=start;
        while(p!=NULL){
            printf("%d ",p->data);
            p=p->next;
        }
}