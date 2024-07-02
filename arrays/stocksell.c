#include <stdio.h>
int main(){
    int arr[]={7,6,4,3,1};
    int buy=arr[0];
    int sold=0;
    for(int i=1;i<(sizeof(arr)/sizeof(arr[0]));i++){
        if(arr[i]<buy){
            buy=arr[i];
            sold=0;
        }
        if(arr[i]>sold){
            sold=arr[i];

        }
    }
   printf("profit: %d",sold-buy);

}
   