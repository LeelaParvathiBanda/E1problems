#include <stdio.h>
#include <stdlib.h>
int main(){
    int flag=0;
    int arr[]={0,-1,2,-3,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=-2;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((arr[i]+arr[j])==x){
                flag=1;
                break;

            }
        }
    }
    if(flag==1){
        printf("yes");
    }
    else{
        printf("no");
    }

}