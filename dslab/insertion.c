#include <stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
int main(){
    int n;
    printf("enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    int i,j;
    printf("enter the array elements : \n");
    for(int k=0;k<n;k++){
        scanf("%d",&arr[k]);
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(arr[j]>arr[i]){
                swap(&arr[j],&arr[i]);
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}