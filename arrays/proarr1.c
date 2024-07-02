// using two extra spaces inorder to slove the problem.
//Given an array arr[] of n integers, construct a Product Array prod[] (of the same size) such that prod[i] is equal to the product of all the elements of arr[] except arr[i]. 
#include <stdio.h>
int main(){
    int arr[]={1,2,3,4,5};
    int arr1[5]={0};
    int arr2[5]={0};
    int temp=1;
    for(int i=0;i<5;i++){
        arr1[i]=temp;
        temp=temp*arr[i];
    }
    temp=1;
    for(int i=4;i>=0;i--){
        arr2[i]=temp;
        temp=temp*arr[i];
    }
    printf("\n product of all the elements of arr[] except arr[i].\n ");
    for(int i=0;i<5;i++){
        printf("%d ",arr1[i]*arr2[i]);
    }
}