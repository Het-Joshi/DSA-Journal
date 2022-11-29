#include<stdio.h>
int main(){

    int size;
    printf("Enter array size: ");
        scanf("%d", &size);
    int A[size];
    // int takes 4 bytes thus A[] takes 20 bytes
    A[0]=10;
    A[1]=20;
    A[2]=30;

    printf("%ld\n\n",sizeof(A));
    printf("=========================\n\n");
    
    //printing array

    for(int x=0; x<size ; x++){
        printf("%d\n",A[x]);
    }

    //Extra elements store GARBAGE Values
}