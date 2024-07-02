
#include <stdio.h>
int search_ele(int arr[],int n,int x){
    int l=0;
    int r=n-1;
    
   
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==x){
            return mid;
        }
        //left sorted part
        else if(arr[l]<arr[mid]){
            if(x<arr[mid]&&x>=arr[l])
                r=mid-1;
            else
                l=mid+1; 

        }
        //right sorted part
        else{
            if(x>arr[mid]&&x<=arr[r])
                l=mid+1;
            else
                r=mid-1;

        }
        
    }
    return -1;
}
int main(){
    int arr[]={5,6,0,1,2};
    int n=5;
    printf("%d",search_ele(arr,n,6));

}
