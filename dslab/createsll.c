#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*start=NULL,*temp,*p;
int main(){
    int x,n;
    printf("enter the size of linked list ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter %d element",i);
        scanf("%d",&x);
        temp->data=x;
        temp->next=NULL;
        if(start==NULL){
            start=temp;
            p=temp;
        }
        else{
            p->next=temp;
            p=temp;
        }
    }                                                                                           
        if(start==NULL)
        printf("linked list is empty \n");
        else{
            p=start;
            printf("the elements of linked list are \n");
            while(p!=NULL){
                printf("%d\n",p->data);
                p=p->next;
            }
        }
        //deletion of the element in singly linked list
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
            printf("element not found to delete");
        }
        else{
            p=start;
            if(pos==1){
                temp=start;
                start=start->next;
                temp=NULL;
                free(temp);
            }
            else if(pos==n){
                while(p->next->next!=NULL)
                    p=p->next;
                temp=p->next;
                p->next=NULL;
                free(temp);
            }
            else{
                for(int i=1;i<pos-1;i++){
                    p=p->next;
                }
                temp=p->next;
                p->next=temp->next;
                temp->next=NULL;
                free(temp);
            }
            
        }
        printf("the elements of the single LL after deletion: ");
        p=start;
        while(p!=NULL){
            printf("%d ",p->data);
            p=p->next;
        }
}
