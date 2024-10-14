#include<stdio.h>
#include<stdlib.h>

void rotate_right(int arr[],int rotation,int size){
    int temp ,prev;
    for (int times = 0;times<rotation;times++){
        temp = arr[size-1];
        for (int i =0;i<size;i++){
            prev = arr[i];
            arr[i] = temp;
            temp = prev;
        }
    }
}
void rotate_left(int arr[],int rotation,int size){
    int temp ,prev;
    for (int times = 0;times<rotation;times++){
        temp = arr[0];
        for (int i =0;i<size-1;i++){
            arr[i]=arr[i+1];
        }
        arr[size-1]=temp;
    }
}
void print_arr(int arr[],int size){
    for (int i = 0;i<size;i++){
        printf("%d\t",arr[i]);
    }printf("\n");
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr,size);
    rotate_right(arr,2,size);
    print_arr(arr,size);
    rotate_left(arr,2,size);
    print_arr(arr,size);
    return 0;
}