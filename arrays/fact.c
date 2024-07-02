#include <stdio.h>
int fact(int n){
    return (n==0)||(n==1)?1:n*fact(n-1);
}
int main(){
    
    printf("%d",fact(17));
    

}