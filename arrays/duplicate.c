#include <stdio.h>
#include <stdlib.h>
int main(){
    int n=9;
    int arr[]={1,2,3,6,3,1,6,2,2,1};
  
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }

    }
    int *hashtable=(int*)calloc(max+1,sizeof(int));
    for(int i=0;i<n;i++){
        hashtable[arr[i]]++;
    }
    for(int k=0;k<=max;k++){
        if(hashtable[k]>1){
            printf("%d",k);
          //  hashtable[k]=0;
        }
    }
    free(hashtable);
}