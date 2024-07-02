#include <stdio.h>
#include <ctype.h>
#include <string.h>
int arr[100];
int top=-1;
void push(int x){
    top=top+1;
    arr[top]=x;

}
int peek(){
    return arr[top];
}
void pop(){
    top=top-1;
}
int ass(char c,int ch1,int ch){
    switch(c){
        case '+':
         return ch1+ch;
        case '-':
         return ch1-ch;
        case '/':
         return ch1/ch;
        case '*':
         return ch1*ch;
        case '%':
         return ch1%ch;
        default:
            return 0;
    }

}
int main(){
     char str[100];
     printf("enter the postfix expression: ");
     scanf("%s",str);
     int i=0;
     while(i<strlen(str)){
        if(isdigit(str[i])){
            int c=str[i]-48;
            push(c);
        }
        else{
            int ch=peek();
            pop();
            int ch1=peek();
            pop();
            int value=ass(str[i],ch1,ch);
            push(value);


        }
        i++;
     }
     int x=peek();
     printf("The postfix evalution of %s is: %d",str,x);


}