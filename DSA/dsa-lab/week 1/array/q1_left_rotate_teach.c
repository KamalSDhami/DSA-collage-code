#include <stdio.h>

void leftrotate (int n, int d, int arr[]){
    int temp [d];
    for (int i =0; i<d; i++){
        temp [i]= arr[i];
    }
    for (int i = d;i<n;i++){
        arr[i-d]=arr[i];
    }
    int j =0;
    for (int i =n-d;i<n;i++){
        arr[i]= temp[j];
        j++;
    }
}
int main(){
    int t,k,n;
    printf("How much test cases you want to run : ");
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        printf("Enter the size of array : ");
        scanf("%d",&n);

        int arr[n];
        printf("Enter the elements of array : ");
        for (int j = 0;j<n;j++){
        scanf("%d",&arr[j]);
        }

        printf("Enter the rotation ");
        scanf("%d",&k);
        leftrotate(n,k,arr);
        for (int j = 0;j<n;j++){
        printf("%d ",arr[j]);
        }
    printf("\n");
    }
    return 0;
}


//reverse (0,k-1,arr)
//reverse (k,n-1,arr)
//reverse (0,n-1,arr)