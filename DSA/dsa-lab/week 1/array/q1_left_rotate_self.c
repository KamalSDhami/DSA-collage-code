#include <stdio.h>
#include <stdlib.h>
//reverse a 1d array
int main (){
    //take data from user
    int n=4,r,arr[] = {1,2,3,4,5};;
    printf("Ener the rotation of array : ");
    scanf("%d",&r);
    //rotate the array
    
    for (int i = 0; i<r;i++){
        int temp = arr[0];
        for (int j = 0 ;j<n-1;j++ ){
            arr[j]= arr[j+1];
        }
        arr[n-1]= temp;
    }
    //display the array
    printf("Updated array :\n");
    for (int i =0 ; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}