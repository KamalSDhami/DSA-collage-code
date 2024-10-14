#include <stdio.h>
#include <stdlib.h>
//reverse a 1d array
int main (){
    //take data from user
    int n;
    printf("Ener the size of array : ");
    scanf("%d",&n);
    int *arr = (int *) calloc(n,sizeof(int));
    printf("Enter the element of array : ");
    for (int i =0 ; i<n; i++){
        scanf("%d",&arr[i]);
    }
    //reverse the array
    
    for (int low =0,high = n-1,temp; low<high;low++,high--){
        temp = arr[low];
        arr[low]= arr[high];
        arr[high]= temp;
    }
    
    //display the array
    for (int i =0 ; i<n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}