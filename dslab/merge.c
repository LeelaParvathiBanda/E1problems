#include <stdio.h>

void Merge(int arr[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[100];
    while(i<=mid&&j<=ub){
        if(arr[i]<=arr[j]){
            b[k]=arr[i];
            k++;i++;
        }
        else{
            b[k]=arr[j];
            k++;j++;
        }
    }
    if(i>mid){
        while(j<=ub){
            b[k]=arr[j];
            k++;j++;
        }
    }
   else{
        while(i<=mid){
            b[k]=arr[i];
            k++;i++;
        }

    }
    for(int i=lb;i<=ub;i++){
        arr[i]=b[i];
    }
}
void mergeSort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        Merge(arr,lb,mid,ub);
        
    }
}
int main(){
    int n;
    printf("no.of elemnts in the array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter %d element : ",i+1);
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
        
    }
}