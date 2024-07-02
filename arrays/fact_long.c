//Find the Factorial of a large number
#include <stdio.h>
int multi(int i,int res[],int res_size ){
    int carry=0;
    for(int k=0;k<res_size;k++){
        int product=(res[k]*i)+carry;
        res[k]=product%10;
        carry=product/10;
    }
    while(carry!=0){
        res[res_size]=carry%10;
        carry=carry/10;
        res_size++;
    }
    return res_size;
    

}
void fact(int n){
    int res[500];
    res[0]=1;
    int res_size=1;
    for(int i=2;i<=n;i++){
        res_size=multi(i,res,res_size);
    }
    for(int i=res_size-1;i>=0;i--){
        printf("%d",res[i]);
    }
}
int main(){
    fact(100);

}