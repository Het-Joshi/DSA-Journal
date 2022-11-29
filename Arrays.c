#include<stdio.h>
int main(){
    int A[5];
    // int takes 4 bytes thus A[] takes 20 bytes
    A[0]=10;
    A[1]=20;
    A[2]=30;

    printf("%ld\n\n",sizeof(A));
    printf("=========================\n\n");
    
    //printing array

    for(int x=0; x<5 ; x++){
        printf("%d\n",A[x]);
    }
}