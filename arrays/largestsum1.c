//Given an array arr[] of size N. The task is to find the sum of the 
//contiguous subarray within a arr[] with the largest sum. kadane's algorithm
#include <stdio.h>
int main(){
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp=0;
    int max=-100;
    for(int i=0;i<n;i++){
        temp=temp+arr[i];
        if(temp>max){
            max=temp;
        }
        if(temp<0){
            temp=0;
        }
    }
    printf("%d",max);
   
   
   
   
}