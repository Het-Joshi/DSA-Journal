#include<stdio.h>

int main(){
    int row,col;
    printf("Enter the number of rows and colomns: ");
        scanf("%d%d",&row, &col);
    int *arr = (int*)malloc(row*col*sizeof(int));

    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            *(arr + i*col +j) = i+j;
        }
    }
    printf("The matrix elements are: \n");
    
    for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         printf("%d ", *(arr + i*col + j)); 
      }
      printf("\n");
   }
   free(arr); 
   return 0;
}