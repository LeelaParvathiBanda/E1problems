#include <stdio.h>
int min(int arr[],int n){
    int low=0;
    int high=n-1;
    int ans=1000;
    if(arr[low]<arr[high]){
        return arr[low];
    }
    while(low<=high){
        int mid=(low+high)/2;
        if((arr[low]==arr[mid])&&(arr[high]==arr[mid])){
            ans=ans<arr[mid]?ans:arr[mid];
            low++;
            high--;
        }
        else if(arr[mid]>arr[high]){
            low=mid+1;
        }
        else{
             ans=ans<arr[mid]?ans:arr[mid];
             high=mid-1;
        }
    }
    return ans;


}
int main(){
    int arr[]={5,6,-2,-1,0,1,2};
    int n=5;
    printf("%d",min(arr,n));

}