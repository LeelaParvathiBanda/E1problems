//Given an array that contains both positive and negative integers, 
//the task is to find the product of the maximum product subarray.
#include <stdio.h>
int max(int n1,int n2){
    return (n1>n2)?n1:n2;
}
int main(){
     int arr[]={-2,-3,4,-1,0,-2,1,5,-3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int left_to_right=1;
    int right_to_lrft=1;
    int ans=-1000;
    for(int i=0;i<n;i++){
        left_to_right *=arr[i];
        right_to_lrft *=arr[(n-1)-i];
        
        ans=max(max(left_to_right,right_to_lrft),ans);

        if(left_to_right==0)
            left_to_right=1;
        if(right_to_lrft==0){
            right_to_lrft=1;
        }
    }
    printf("%d",ans);
}