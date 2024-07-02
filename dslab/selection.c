#include <stdio.h>
int main(){
    int arr[6]={17,54,93,26,77,31};
    int temp=0;
    for(int i=0;i<6;i++){
        int min=i;
        for(int j=i+1;j<6;j++){
         
                if(arr[j]<arr[min]){
                     min=j;
               
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    for(int k=0;k<6;k++){
        printf("%d ",arr[k]);
    }
}