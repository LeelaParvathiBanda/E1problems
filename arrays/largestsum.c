//Given an array arr[] of size N. The task is to find the sum of the 
//contiguous subarray within a arr[] with the largest sum. 
#include <stdio.h>
int main(){
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
   int  n=sizeof(arr)/sizeof(arr[0]);
   int max=-100;
   
   int i1,j1;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+arr[j];
            if(sum>max){
                max=sum;
                i1=i;
                j1=j;
                
            }


        }
    }
    printf("%d\n",max);
    for(int i=i1;i<=j1;i++){
        printf("%d ",arr[i]);
    }
}

