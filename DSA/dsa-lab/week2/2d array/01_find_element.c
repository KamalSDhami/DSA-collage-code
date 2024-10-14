
/*Problem Statement: Given a matrix of size n X n, where every row and every column is sorted in 
increasing order. Write an algorithm and a program to find whether the given key element is present in 
the matrix or not. (Linear time complexity)
Input Format:
First line contains n (the size of matrix).
For next n input lines, each line contains space-separated n integers describing each row of thematrix.
Last line of input will contain key integer to be searched
OutputFormat:
Output will be “Present” if the key element is found in the array, otherwise print “Not Present”.
Sample:
Input: 
4 
10 20 30 40
15 25 34 41
27 29 35 45
32 33 38 49
33
Output:
Present*/
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int key;
    scanf("%d",&key);
    int i=0,j=n-1;
    while(i<n && j>=0)
    {
        if(a[i][j]==key)
        {
            printf("Present");
            return 0;
        }
        else if(a[i][j]>key)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    printf("Not Present");
    return 0;
}
