#include <stdio.h>
int main(){
    int arr[3][3]={{1,1,1},{2,2,2},{3,3,3}};
    int pro[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            pro[i][j]=arr[j][i];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d",pro[i][j]);
        }
    }

}