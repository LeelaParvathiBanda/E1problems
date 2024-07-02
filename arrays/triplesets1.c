//Given a array of distinct elements. The task is to find triplets in the array whose sum is zero.
//using sorting techinque
#include <stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int lb,int ub){
    int pivot=arr[lb];
    int i=lb;
    int j=ub;
    while(i<j){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[j],&arr[lb]);
    return j;
}
void Quick(int arr[],int lb,int ub){
    int loc;
    if(lb<ub){
        loc=partition(arr,lb,ub);
        Quick(arr,lb,loc-1);
        Quick(arr,loc+1,ub);
    }
}
int main(){
     int arr[]={0,-1,2,-3,1};
     //int arr[]={-2,4,-1,0,1,5,-3};
     int n=sizeof(arr)/sizeof(arr[0]);
     Quick(arr,0,n-1);
    
     int flag=0;
     for(int i=0;i<n-1;i++){
        
        int l=i+1;
        int r=n-1;
        while(l<r){
            if((arr[i]+arr[l]+arr[r])==0){
                printf("%d %d %d \n",arr[i],arr[l],arr[r]);
                l++;
                r--;
                flag=1;
            }
            else if((arr[i]+arr[l]+arr[r])>0){
                r--;
            }
            else{
                l++;
            }
        }
    }
     if(flag==0){
        printf("not found");
    }

}
