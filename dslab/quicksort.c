#include <stdio.h>
void swap(int *a,int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int lb,int ub){
    int pivot,i,j;
    pivot=arr[lb];
    i=lb;
    j=ub;
    while(i<j){
        while(pivot>=arr[i])
        i++;
        while(pivot<arr[j])
        j--;
        if(i<j)
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[lb],&arr[j]);
    return j;
}
void Quicksort(int arr[], int lb,int ub){
    if(lb<ub){
    int loc;
    loc=partition(arr,lb,ub);
    Quicksort(arr,lb,loc-1);
    Quicksort(arr,loc+1,ub);
}
}
int main(){
    int n,lb,ub;
    printf("enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    lb=0;
    ub=n-1;
    printf("enter the array elements : \n");
    for(int k=0;k<n;k++){
        printf("enter:" );
        scanf("%d",&arr[k]);
    }
    Quicksort(arr,lb,ub);
    for(int l=0;l<n;l++){
        printf("%d ",arr[l]);
    }
}