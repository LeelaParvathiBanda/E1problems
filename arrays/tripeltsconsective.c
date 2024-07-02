//Given a array of distinct elements. The task is to find triplets  subarray in the array whose sum is zero.
#include <stdio.h>
int main(){
     int arr[]={-2,-3,4,-1,0,-2,1,5,-3};
     int n=sizeof(arr)/sizeof(arr[0]);
     for(int i=0;i<n-2;i++){
        if(arr[i]+arr[i+1]+arr[i+2]==0){
            printf("%d , %d ,%d ",arr[i],arr[i+1],arr[i+2]);

        }
     }
}